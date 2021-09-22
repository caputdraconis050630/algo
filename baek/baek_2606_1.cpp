#include <bits/stdc++.h>
using namespace std;

bool vis[101];
vector<int> v[101];
int ans = 0;

void DFS(int n)
{
    if (!vis[n])
    {
        ans++;
        vis[n] = true;
    }
    for (int idx = 0; idx < v[n].size(); idx++)
    {
        if (vis[v[n][idx]])
            continue;
        else
            DFS(v[n][idx]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T; // 컴퓨터의 수
    cin >> N; // 직접 연결되어 있는 컴퓨터 쌍의 수

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); // 양방향 그래프이기 때문!
    }
    vis[1] = true;
    DFS(1);
    cout << ans;
    return 0;
}