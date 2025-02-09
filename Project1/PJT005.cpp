// ���� 2933�� �̳׶�

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

// �޸� �ʱ�ȭ �Լ�
void reset() {
	memset(check, 0, sizeof(check));
	Move.clear();
}

// ����⸦ ���� �̳׶��� �ı��ϴ� �Լ�
void hit_mineral(int x, int dir) {
	if (dir % 2 == 0) { // ���ʿ��� ������
		for (int y = 1; y <= C; y++) {
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
	}
	else { // �����ʿ��� ����
		for (int y = C; y >= 1; y--) {
			if (map[R - x + 1][y] == 'x') {
				map[R - x + 1][y] = '.';
				break;
			}
		}
	}
}


// BFS (�ʺ�켱 Ž��)
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

// Ŭ�����͸� �ٴ����� ����߸��� �Լ�
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

//���� �����ϴ� �Լ�
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

// ���߿� �� �ִ� Ŭ������ ã�� �Լ�
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

// ���� ����ϴ� �Լ�
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