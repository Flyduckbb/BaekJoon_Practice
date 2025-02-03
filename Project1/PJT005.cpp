// 백준 '미네랄' 2933

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<string>> cave(R, vector<string>(C));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << i << j;
			cin >> cave[i][j];
		}
	}

	for (const auto& row : cave) {
		for (const auto& str : row) {
			cout << str << " ";
		}
		cout << endl;
	}
}