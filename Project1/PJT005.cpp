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

    cout << "��� ���� �Է��ϼ��� : ";
    cin >> Row >> Column;
    cin.ignore();  // ���ۿ� ���� �ִ� ���� ���� ����

    vector<vector<string>> cave(Row, vector<string>(Column));

    cout << "MAP�� �˷��ּ��� : ";

    for (int i = 0; i < Row; ++i) {
        string line;
        getline(cin, line);  // �� �� �Է¹ޱ�

        // �Է¹��� �� ���� �� ���ڸ� 2���� �迭�� ����
        for (int j = 0; j < Column; ++j) {
            if (j < line.length()) {  // �Էµ� ���ڰ� ������ ����
                cave[i][j] = line[j];
            }
            else {  // ���� �Է��� �����ϸ� �⺻��("") ����
                cave[i][j] = "";
            }
        }
    }

    /*
    for (int i = 0; i < Row; ++i) {
        string line;
        getline(cin, line);  // �� �� �Է¹ޱ�

        istringstream iss(line);  // �Է¹��� ���ڿ��� ���� �������� �и�
        for (int j = 0; j < Column; ++j) {
            if (!(iss >> cave[i][j])) {  // �Է��� �����ϸ� �⺻��("") ����
                cave[i][j] = "";
            }
        }
    }
    */

    cout << "ȭ���� �� Ƚ���� �Է����ּ��� : ";

    cin >> cnt;
    vector<int> numbers(cnt);

    for (int i = 0; i < cnt; ++i) {
        cin >> targetR;
        numbers[i] = targetR;
    }

    for (int i = 0; i < cnt; ++i) {
        for (int c = 0; c < Column; ++c) {
            if (cave[Row - numbers[i] - 1][c] == "X") {
                cout << "�ı�!" << endl;
                cave[Row - numbers[i] - 1][c] = ".";
            }
        }
    }


    // �Էµ� �� ���
    cout << "\n�Էµ� 2���� ���ڿ� �迭:\n";
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

// �迭 ũ�� �Է� �ޱ�
cout << "��(row)�� ��(column)�� ũ�⸦ �Է��ϼ���: ";
cin >> rows >> cols;

// 2���� ���� ���� (���ڿ� Ÿ��)
vector<vector<string>> strMatrix(rows, vector<string>(cols));

// �� �Է� �ޱ�
cout << "�迭�� �� ��ҿ� �� ���ڿ��� �Է��ϼ���:\n";
for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        cout << "strMatrix[" << i << "][" << j << "]: ";
        cin >> strMatrix[i][j];
    }
}

// �Էµ� �� ���
cout << "\n�Էµ� 2���� ���ڿ� �迭:\n";
for (const auto& row : strMatrix) {
    for (const auto& str : row) {
        cout << str << " ";
    }
    cout << endl;
}

return 0;
*/