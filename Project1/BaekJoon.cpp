/*
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//���� '�Ӹ�������� Ȯ���ϱ�' 10988�� (��) -> IDLE������ ���� �۵��ϳ� ���ؿ����� �ȵ� / ���� �ľ� �� ����
int main()
{
    string a;
    cin >> a;

    char* arry = new char[a.size()+1];

    for (int i = 0; i < a.size(); ++i) {
        arry[i] = a[i];
    }
    arry[a.size()]='\0';

    if (a.size() == 1) {
        cout << 1;
        return 0;
    }

    int pelindrum = 1;
    if (a.size() % 2 == 1)
    {
        for (int i = 0; i < a.size() / 2; i++) {
            if (i == a.size() - i)
                break;
            else if (arry[i] != arry[a.size() - 1 - i])
                pelindrum = 0;
        }
    }
    else if (a.size() % 2 == 0)
    {
        for (int i = 0; i < a.size() / 2; i++) {
            if (arry[i] != arry[a.size() - 1 - i])
            {
                pelindrum = 0;
            }
        }
    }

    cout << pelindrum;

    delete[] arry;

    return 0;
}
*/

/*
//���� '��� ����' 2738�� (��) -> ȿ�� ���� ���� / ������ �ľ� �� ����
int main()
{
    int horizon, vertical = 0;
    cin >> horizon >> vertical;

    std::vector<std::vector<int>> array_A(horizon, std::vector<int>(vertical));

    for (int i = 0; i < horizon; i++) {
        for (int j=0; j < vertical; j++) {
            cin >> array_A[i][j];
        }
    }

    std::vector<std::vector<int>> array_B(horizon, std::vector<int>(vertical));

    for (int i = 0; i < horizon; i++) {
        for (int j = 0; j < vertical; j++) {
            cin >> array_B[i][j];
        }
    }

    for (int i = 0; i < horizon; i++) {
        for (int j = 0; j < vertical; j++) {
            cout << array_A[i][j] + array_B[i][j] << " ";
            if (j == vertical - 1)
                cout << "\n";
        }
        if (i == horizon - 1)
            cout << "\n";
    }
}
*/

/*
// ���� '���� ��ȯ' 2754�� (��)
int main() {
    string str;
    int base;
    int result = 0;
    cin >> str >> base;
    for (int i = 0; i < str.length(); i++) {
        int strToNum = str[str.length() - (i + 1)];
        if ('0' <= strToNum && strToNum <= '9') {
            result += (strToNum - '0') * int(pow(base, i));
        }
        else {
            result += (strToNum - 'A' + 10) * int(pow(base, i));
        }
    }
    cout << result;
}
*/