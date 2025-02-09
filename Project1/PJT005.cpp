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

// 메모리 초기화 함수
void reset() {
	memset(check, 0, sizeof(check));
	Move.clear();
}

// 막대기를 던져 미네랄을 파괴하는 함수
void hit_mineral(int x, int dir) {
	if (dir % 2 == 0) { // 왼쪽에서 오른쪽
		for (int y = 1; y <= C; y++) {
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
	}
	else { // 오른쪽에서 왼쪽
		for (int y = C; y >= 1; y--) {
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
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

// 클러스터를 바닥으로 떨어뜨리는 함수
int drop_Cluster(int x, int y) {
	int cnt = 0;
	for (int i = x + 1; i <= R; i++) {
		if (map[i][y] == 'x') {
			if (check[i][y] == 0)
				return INF;
			else
				return cnt + i;
		}
		return cnt;
	}
}

//지도 구현하는 함수
void remake_map() {
	int down = INF;
	for (int i = 0; i < Move.size(); i++) {
		int cnt = drop_Cluster(Move[i].first, Move[i].second);
		if (cnt == INF)
			continue;
		else
			down = min(cnt, down);
	}
	if (down == INF)
		return;
	for (int i = 0; i < Move.size(); i++) {
		int x = Move[i].first, y = Move[i].second;
		map[x][y] = '.';
	}
	for (int i = 0; i < Move.size(); i++) {
		int x = Move[i].first, y = Move[i].second;
		map[x + down][y] = 'x';
	}
}

// 공중에 떠 있는 클러스터 찾는 함수
bool find_cluster() {
	bool can = false;
	for (int i = 1; i <= C; i++) {
		if (check[R][1] == 0 && map[R][i] == 'x') bfs(R, i);
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'x' && check[i][j] == 0) {
				Move.push_back({ i,j });
				can = true;
			}
		}
	}
	return can;
}

// 지도 출력하는 함수
void show_map() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve() {
	for (int i = 0; i < Throw.size(); i++) {
		reset();
		hit_mineral(Throw[i], i);
		if (!find_cluster())
			continue;
		remake_map();
	}
	show_map();
}

int main() {
	cin.tie(0);
	cout.tie(0);
	
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> Stick_Cnt;
	for (int i = 1; i <= Stick_Cnt; i++) {
		int x;
		cin >> x;
		Throw.push_back(x);
	}
	solve();
	return 0;
}