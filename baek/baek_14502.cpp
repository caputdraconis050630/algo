#include <bits/stdc++.h>
#define X first
#define Y second

typedef pair<int, int> Pair;
using namespace std;

int N, M;
int board[10][10];

int virus_board[10][10]; // 바이러스가 퍼지는걸 확인할 보드
int dist[10][10];        // 바이러스 확산에 걸리는 시간

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<Pair> V;
    queue<Pair> Q;

    fill(&dist[0][0], &dist[9][10], -1);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            virus_board[i][j] = board[i][j];

            if (board[i][j] == 2)
            {
                V.push_back(make_pair(i, j));
                Q.push(make_pair(i, j));

                dist[i][j] = 0;
            }
        }
    }

    while (!Q.empty())
    {
        Pair cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 or ny < 0 or nx >= N or ny >= M)
                continue;
            if (dist[nx][ny] != -1 and dist[nx][ny] <= dist[cur.X][cur.Y] + 1)
                continue;
            if (virus_board[nx][ny] != 0)
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            virus_board[nx][ny] = 2;
            Q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}
