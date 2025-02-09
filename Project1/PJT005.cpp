// 백준 2933번 미네랄

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

#define P pair<int, int>
//#define F first
//#define S second
#define INF 987654321

using namespace std;

int R, C;
char map[101][101];
int check[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int Stick_Cnt;
vector<int> Throw;
vector<P> Move;

// 막대기를 던져 미네랄을 파괴하는 함수
void hit_mineral(int x, int dir) {
	if (dir % 2 == 0) {
		int y = 1;
		while (1) {
			if (y > C) break;
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
		y++;
	}
	else {
		int y = C;
		while (1) {
			if (y < 1) break;
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
		y--;
	}
}

// BFS (너비우선 탐색)
void bfs(int X, int Y) {
	queue<P> q;
	q.push({ X, Y });
	check[X][Y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 && xx <= R && yy >= 1 && yy <= C) {
				if (check[xx][yy] == 0 && map[xx][yy] == 'x') {
					check[xx][yy] = 1;
					q.push({ xx, yy });
				}
			}
		}
	}
}

// 공중에 떠 있는 클러스터 찾는 함수
bool find_cluster() {
	bool can = false;
	for (int i = 1; i <= C; i++) {
		if (check[R][1] == 0 && map[C][i] == 'x') bfs(R, i);
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'x' && check[i][j] == 0) {
				Move.push_back({ i,j });
				can = true;
			}
		}
	}
}

// 클러스터를 바닥으로 떨어뜨리는 함수
int drop_Cluster(int x, int y) {
	int cnt = 0;
	for (int i = x + 1; i <= R; i++) {
		if (map[i][y] == 'x') {
			if (check[i][y] == 0)
				return INF;
			else
				return cnt++;
		}
		return cnt;
	}
}