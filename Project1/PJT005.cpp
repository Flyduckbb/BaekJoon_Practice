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
#define F first
#define S second
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

