// BFS
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002]; // 전체적인 맵

int fire[1002][1002]; // 불 이동 시간 기록
int dist[1002][1002]; // 사람 이동 시간 기록

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    queue<pair<int, int> > fireQ;
    queue<pair<int, int> > Q;
    int R, C;
    cin >> R >> C;

    // memset(fire, -1, sizeof(fire)); // 불이 없는 곳은 -1
    // memset(dist, -1, sizeof(dist)); // 이동하지 못하는 곳은 -1

    for (int i = 0; i < R; i++)
    {
        fill(fire[i], fire[i] + C, -1);
        fill(dist[i], dist[i] + C, -1);
        cin >> board[i];

        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == 'F')
            { // 불이 난 곳은 0
                fire[i][j] = 0;
                fireQ.push(make_pair(i, j));
            }

            if (board[i][j] == 'J')
            {
                Q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    // 불에 대한 BFS
    while (!fireQ.empty())
    {
        pair<int, int> cur = fireQ.front();
        fireQ.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                continue; // 범위 초과
            }
            if (board[nx][ny] == '#')
                continue;
            if (fire[nx][ny] >= 0)
                continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            fireQ.push(make_pair(nx, ny));
        }
    }

    // 사람에 대한 BFS
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                cout << dist[cur.X][cur.Y] + 1 << "\n";
                return 0;
            }

            if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
                continue; // 방문하지 않은 곳은 -1이기 때문/ 앞 조건은 벽 때문에 불이 도달하지 못하는 곳(-1이 저장된 부분)은 가능하도록 해준다.

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    cout << "IMPOSSIBLE\n";
}