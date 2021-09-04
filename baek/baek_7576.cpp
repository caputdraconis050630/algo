#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    int M, N;
    cin >> M >> N;

    queue<pair<int, int> > Q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            { // 이미 익어있는 토마토
                Q.push(make_pair(i, j));
            }

            if (board[i][j] == 0)
            { // 익지 않은 토마토
                dist[i][j] == -1;
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (dist[nx][ny] >= 0)
                continue; // 이미 익어있는 토마토나 토마토가 없는 칸일 경우

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == -1)
            {
                // 안익은 감자가 아직 있을 때
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
}