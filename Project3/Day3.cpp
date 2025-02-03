// ���� '�似Ǫ�� ����' 1158
/*
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int max, gap;
    cin >> max >> gap;

    queue<int> q;

    cout << '<';
    for (int i = 1; i <= max; i++)
        q.push(i);

    while (!q.empty()) {
        for (int i = 0; i < gap - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();

        if (q.empty()) cout << '>';
        else cout << ", ";
    }
    return 0;
}
*/


// ���� 'ȸ�翡 �ִ� ���' 7785
/*
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    map<string, string, greater<string>> log;

    while (cnt--) {
        string name, record;
        cin >> name >> record;

        log[name] = record;
    }

    map<string, string> ::iterator it;
    for (it = log.begin(); it != log.end(); ++it)
    {
        if (it->second == "enter")
        {
            cout << it->first << '\n';
        }
    }
}
*/

//=============================================================================================

/*
// ���� 'Ʈ�� ��ȸ' 1991
#include <iostream>
using namespace std;

// ��� ����
struct node { 
    char cur; 
    int left, right; 
};

// �ִ� 26���� ��尡 ��õǾ� �����Ƿ� �� ����
node nodes[26];

// ���� ��ȸ
void Preorder(int cur) {
    cout << nodes[cur].cur;
    if (nodes[cur].left) 
        Preorder(nodes[cur].left);
    if (nodes[cur].right) 
        Preorder(nodes[cur].right);
}

// ���� ��ȸ
void Inorder(int cur) {
    if (nodes[cur].left) 
        Inorder(nodes[cur].left);
    cout << nodes[cur].cur;
    if (nodes[cur].right) 
        Inorder(nodes[cur].right);
}

// ���� ��ȸ
void Postorder(int cur) {
    if (nodes[cur].left) 
        Postorder(nodes[cur].left);
    if (nodes[cur].right) 
        Postorder(nodes[cur].right);
    cout << nodes[cur].cur;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        char cur, left, right;
        cin >> cur >> left >> right;

        nodes[cur - 'A'].cur = cur;
        if (left != '.') 
            nodes[cur - 'A'].left = left - 'A';
        if (right != '.') 
            nodes[cur - 'A'].right = right - 'A';
    }

    Preorder(0);
    cout << '\n';
    Inorder(0);
    cout << '\n';
    Postorder(0);
}
*/

/*
// ���� '�ִ� ��' 11279
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> heap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // �۾��� Ƚ�� ���� ���� �� �Է�
    int cnt;
    cin >> cnt;

    // ť�� �۾� Ƚ����ŭ ���� �Է¹޾� ������ ����
    for (int i=0; i < cnt; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (heap.empty() == 1)
                cout << 0 << '\n';
            else
            {
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
        else {
            heap.push(num);
        }
    }
    return 0;
}
*/

/*
// ���� '���̷���' 2606
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

// ���� �� �迭 ����
int com, connect;
int cnt = 0;
int arr[MAX][MAX];
bool visited[MAX] = { 0, };
queue<int> q;

// BFS
void bfs(int v) {
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= com; i++) {
            if (arr[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> com >> connect;

    for (int i = 0; i < connect; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    bfs(1);

    cout << cnt;
}
*/

/*
// ���� '�̷� Ž��' 2178
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 4���� ����
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int Dist[101][101]; // �Ÿ��� ������ �迭
char Map[101][101]; // �̷θ� ���� �迭
int visited[101][101]; // �湮�� ��ġ�� ǥ���� �迭

// �ʺ� �켱 Ž��
void BFS(int start_x, int start_y) {
    visited[start_x][start_y] = 1;

    queue<pair<int, int>> Q;
    Q.push(make_pair(start_x, start_y));

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;

        Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
                if (Map[next_x][next_y] == '1' && visited[next_x][next_y] == 0) {
                    Dist[next_x][next_y] = Dist[x][y] + 1;
                    // ���� ��ġ�� �̵�
                    visited[next_x][next_y] = 1;
                    // �湮���� ó��
                    Q.push(make_pair(next_x, next_y));
                    // ť�� ���� �־ ���� ��ǥ���� BFS ����
                }
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> Map[i];
    }
    BFS(0, 0);
    cout << Dist[N - 1][M - 1] + 1 << '\n'; // �̷��� ������������ �Ÿ� ���
    return 0;
}
*/


// ���� '���� �˻� Ʈ��' 5639
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;

void Post(int st, int en) {
    if (st >= en)
        return;

    if (st == en - 1) {
        cout << arr[st] << '\n';
        return;
    }

    int idx = st + 1;
    while (idx < en) {
        if (arr[st] < arr[idx])
            break;
        idx++;
    }

    Post(st + 1, idx);
    Post(idx, en);
    cout << arr[st] << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
        arr.push_back(n);

    Post(0, arr.size());
    return 0;
}