#include <bits/stdc++.h>
using namespace std;

int board[500][500];
bool vis[500][500];

#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int n, m;
    cin >> n >> m;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> board[i][k];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            int tmp = 0;
            if (vis[i][k] || board[i][k] == 0)
            {
                // 방문을 했거나 그림이 칠해져있지 않을 때
                // 스킵할 부분
                continue;
            }
            else
            {
                queue<pair<int, int>> Q;
                cnt++;
                // BFS 해야되는 부분
                vis[i][k] = 1;
                Q.push({i, k});
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    tmp++;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        {
                            continue;
                            // 조건 미성립
                        }
                        if (vis[nx][ny] || board[nx][ny] != 1)
                        {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                mx = max(mx, tmp);
            }
        }
    }

    cout << cnt << "\n"
         << mx;
}