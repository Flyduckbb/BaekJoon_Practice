// 백준 '주사위 굴리기' 14499
/*
#include<iostream>
#include<vector>
using namespace std;

int N, M, x, y, k;
int map[20][20];
int command[1000];
int dice[6];

// 지도를 벗어나는 경우 확인
int RangeCheck(int d) {
    if (d == 1) {
        if (y == M - 1) return 0;
    }
    else if (d == 2) {
        if (y == 0) return 0;
    }
    else if (d == 3) {
        if (x == 0) return 0;
    }
    else if (d == 4) {
        if (x == N - 1) return 0;
    }
    return 1;
}

void Movement(int d) {
    int temp = dice[0];
    if (d == 1) {
        y++;
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }
    else if (d == 2) {
        y--;
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
    else if (d == 3) {
        x--;
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    else if (d == 4) {
        x++;
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}

void rollDice() {
    for (int i = 0; i < k; i++) {
        if (!RangeCheck(command[i])) {
            continue;
        }

        Movement(command[i]);
        if (map[x][y] == 0) {
            map[x][y] = dice[1];
        }
        else {
            dice[1] = map[x][y];
            map[x][y] = 0;
        }
        cout << dice[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> x >> y >> k;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < k; i++)
        cin >> command[i];

    rollDice();
}
*/

// 백준 '행렬 제곱' 10830
#include <iostream>
using namespace std;

long long N, B;
long long matrix[5][5];
long long unitMatrix[5][5] = { 0 };
long long temp[5][5];

void Matrix_Multi(long long x[5][5], long long y[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                temp[i][j] += (x[i][k] * y[k][j]);
            }
            temp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            x[i][j] = temp[i][j];
    }
}

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
        unitMatrix[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1)
            Matrix_Multi(unitMatrix, matrix);
        Matrix_Multi(matrix, matrix);
        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << unitMatrix[i][j] << " ";
        cout << endl;
    }
}