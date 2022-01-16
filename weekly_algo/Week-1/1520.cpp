#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int M, N, ans = 0;
int board[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int> > Q;

    // Set starting point
    Q.push(make_pair(0, 0));

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.X == M - 1 && cur.Y == N - 1)
        {
            ans++;
        }
        else
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                // Filtering OOB
                if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                {
                    continue;
                }

                // Filtering unavailable height
                if (board[nx][ny] >= board[cur.X][cur.Y])
                {
                    continue;
                }

                Q.push(make_pair(nx, ny));
            }
        }
    }

    cout << ans << "\n";
}