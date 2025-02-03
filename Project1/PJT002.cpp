/*
#include <iostream>
#include <vector>

using namespace std;


int main() {
	int order = 0;

	cin >> order;

	stack<int> s;

	for (int i = 0; i < order; i++) {

		string command;

		cin >> command;

		if (command == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (command == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (command == "size")
		{
			cout << s.size() << '\n';
		}
		else if (command == "empty")
		{
			if (!s.empty())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (command == "top")
		{
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}
*/

/*
// 백준 '색종이' 2563번
int main() {
	int coordinate[100][100] = { 0 };

	int count = 0;
	cin >> count;

	int area = 0;
	int flag = 1;

	for (int i = 0; i < count; i++) {
		int horizon, vertical = 0;
		cin >> horizon >> vertical;

		int target_hor = horizon + 10;
		int target_ver = vertical + 10;

		for (int coor_x = horizon-1; coor_x < 100; coor_x++) {
			for (int coor_y = vertical-1; coor_y < 100; coor_y++) {
				if (coordinate[coor_x][coor_y] != flag) {
					coordinate[coor_x][coor_y] = flag;
				}
				if (coor_y == target_ver-2)
					break;
			}
			if (coor_x == target_hor-2)
				break;
		}
	}


	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (coordinate[i][j] == 1) area++;
		}
	}

	cout << area;

	return 0;
}
*/

/*
// 백준 '분수찾기' 1193번
int main() {
	int N;
	cin >> N;

	int i = 1;
	while (N > i) {
		N -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - N << '/' << N << endl;
	else
		cout << N << '/' << i + 1 - N << endl;
}



// 백준 '랜선 자르기' 1654번
vector<long long int>LAN;
int main() {
	long long int sum = 0;
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long int num;
		cin >> num;
		LAN.push_back(num);
	}

	for (int i = 0; i < n; i++)
		sum += LAN[i];

	long long int start = 1;
	long long int end = sum;
	long long int height = 0;
	while (start <= end)
	{
		long long int total = 0;
		long long int mid = (start + end) / 2;
		for (int i = 0; i < LAN.size(); i++)
			total += LAN[i] / mid;
		if (total < m)
			end = mid - 1;
		else
		{
			height = mid;
			start = mid + 1;
		}
	}
	cout << height;
	return 0;
}
*/