// Unsolved

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int M, N, ans = 0;
unsigned short board[501][501];
unsigned short road[501][501];
bool chk[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> M >> N;
    fill(&road[0][0], &road[500][501], 0);
    fill(&chk[0][0], &chk[500][501], false);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> Q;

    // Set starting point
    Q.push(make_pair(M - 1, N - 1));
    road[M - 1][N - 1] = 1;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.X == 0 && cur.Y == 0)
        {
            continue;
        }

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
            if (board[nx][ny] <= board[cur.X][cur.Y])
            {
                continue;
            }
            if (nx == 0 && ny == 0)
            {
                road[nx][ny] += 1;
            }
            else
            {
                road[nx][ny] = 1;
            }

            Q.push(make_pair(nx, ny));
        }
    }

    cout << road[0][0] << "\n";
}
