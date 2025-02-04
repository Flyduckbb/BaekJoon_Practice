#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;

int Row, Column, cnt, targetR;

int main() {

    cout << "행과 열을 입력하세요 : ";
    cin >> Row >> Column;
    cin.ignore();  // 버퍼에 남아 있는 개행 문자 제거

    vector<vector<string>> cave(Row, vector<string>(Column));

    cout << "MAP을 알려주세요 : ";

    for (int i = 0; i < Row; ++i) {
        string line;
        getline(cin, line);  // 한 줄 입력받기

        // 입력받은 한 줄의 각 문자를 2차원 배열에 저장
        for (int j = 0; j < Column; ++j) {
            if (j < line.length()) {  // 입력된 문자가 있으면 저장
                cave[i][j] = line[j];
            }
            else {  // 만약 입력이 부족하면 기본값("") 저장
                cave[i][j] = "";
            }
        }
    }

    /*
    for (int i = 0; i < Row; ++i) {
        string line;
        getline(cin, line);  // 한 줄 입력받기

        istringstream iss(line);  // 입력받은 문자열을 공백 기준으로 분리
        for (int j = 0; j < Column; ++j) {
            if (!(iss >> cave[i][j])) {  // 입력이 부족하면 기본값("") 유지
                cave[i][j] = "";
            }
        }
    }
    */

    cout << "화살을 쏠 횟수를 입력해주세요 : ";

    cin >> cnt;
    vector<int> numbers(cnt);

    for (int i = 0; i < cnt; ++i) {
        cin >> targetR;
        numbers[i] = targetR;
    }

    for (int i = 0; i < cnt; ++i) {
        for (int c = 0; c < Column; ++c) {
            if (cave[Row - numbers[i] - 1][c] == "X") {
                cout << "파괴!" << endl;
                cave[Row - numbers[i] - 1][c] = ".";
            }
        }
    }


    // 입력된 값 출력
    cout << "\n입력된 2차원 문자열 배열:\n";
    for (const auto& row : cave) {
        for (const auto& str : row) {
            cout << str << " ";
        }
        cout << endl;
    }


    return 0;
}



/*
int rows, cols;

// 배열 크기 입력 받기
cout << "행(row)과 열(column)의 크기를 입력하세요: ";
cin >> rows >> cols;

// 2차원 벡터 선언 (문자열 타입)
vector<vector<string>> strMatrix(rows, vector<string>(cols));

// 값 입력 받기
cout << "배열의 각 요소에 들어갈 문자열을 입력하세요:\n";
for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        cout << "strMatrix[" << i << "][" << j << "]: ";
        cin >> strMatrix[i][j];
    }
}

// 입력된 값 출력
cout << "\n입력된 2차원 문자열 배열:\n";
for (const auto& row : strMatrix) {
    for (const auto& str : row) {
        cout << str << " ";
    }
    cout << endl;
}

return 0;
*/