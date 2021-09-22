#include <bits/stdc++.h>
using namespace std;

int ans;
bool check[105];

vector<int> V[101];

void bfs(int n)
{
    if (!check[n])
    {
        // 방문하지 않았다면
        check[n] = true;
        ans++;
    }

    for (int i = 0; i < V[n].size(); i++)
    {
        if (check[V[n][i]] == true)
        {
            continue;
        }
        else
        {
            bfs(V[n][i]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k; // 주어질 연결 상태의 개수
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    check[1] = true;
    bfs(1);

    cout << ans << "\n";
}