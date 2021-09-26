#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V[1001];
bool chk[1001]; // 방문 체크v
int ans;

void dfs(int x)
{
    chk[x] = true;

    for (int i = 0; i < V[x].size(); i++)
    {
        int next = V[x][i];
        if (!chk[next])
        {
            dfs(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; // N : 정점의 개수  M : 연결 요소의 개수

    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;

        V[x].push_back(y);
        V[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (chk[i] == false)
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans << '\n';
}