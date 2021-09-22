#include <bits/stdc++.h>
using namespace std;

int n;   // 컴퓨터의 개수
int ans; // 정답
vector<int> V[101];
bool check[105];
queue<int> Q;

void link(int x, int y)
{
    V[x].push_back(y);
    V[y].push_back(x);
}

void bfs()
{
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        ans++;

        for (int i = 0; i < V[cur].size(); i++)
        {
            if (check[V[cur].at(i) != true])
            {
                // 방문하지 않았더라면
                Q.push(V[cur].at(i));
                check[V[cur].at(i)] = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int k; // 주어질 연결 상태의 개수
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        link(x, y);
    }

    Q.push(1);
    check[1] = true;

    bfs();

    cout << ans - 1 << "\n";
}