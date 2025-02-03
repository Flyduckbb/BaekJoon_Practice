// 백준 '요세푸스 문제' 1158
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


// 백준 '회사에 있는 사람' 7785
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
// 백준 '트리 순회' 1991
#include <iostream>
using namespace std;

// 노드 선언
struct node { 
    char cur; 
    int left, right; 
};

// 최대 26개의 노드가 명시되어 있으므로 선 지정
node nodes[26];

// 전위 순회
void Preorder(int cur) {
    cout << nodes[cur].cur;
    if (nodes[cur].left) 
        Preorder(nodes[cur].left);
    if (nodes[cur].right) 
        Preorder(nodes[cur].right);
}

// 중위 순회
void Inorder(int cur) {
    if (nodes[cur].left) 
        Inorder(nodes[cur].left);
    cout << nodes[cur].cur;
    if (nodes[cur].right) 
        Inorder(nodes[cur].right);
}

// 후위 순회
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
// 백준 '최대 힙' 11279
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> heap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 작업할 횟수 변수 선언 및 입력
    int cnt;
    cin >> cnt;

    // 큐에 작업 횟수만큼 값을 입력받아 데이터 저장
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
// 백준 '바이러스' 2606
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

// 변수 및 배열 지정
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
// 백준 '미로 탐색' 2178
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 4방향 벡터
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int Dist[101][101]; // 거리를 저장할 배열
char Map[101][101]; // 미로를 만들 배열
int visited[101][101]; // 방문한 위치를 표시할 배열

// 너비 우선 탐색
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
                    // 다음 위치로 이동
                    visited[next_x][next_y] = 1;
                    // 방문했음 처리
                    Q.push(make_pair(next_x, next_y));
                    // 큐에 집어 넣어서 다음 좌표에서 BFS 시작
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
    cout << Dist[N - 1][M - 1] + 1 << '\n'; // 미로의 끝지점에서의 거리 출력
    return 0;
}
*/


// 백준 '이진 검색 트리' 5639
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