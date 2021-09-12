#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int w, h;
string board[1005];
int dist[1005][1005];
int fire[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    deque<pair<int, int> > Q;
    deque<pair<int, int> > fireQ;
    int idx = -100;

    while (t--)
    {
        fill(board, board + 1005, ' ');
        fill(&dist[0][0], &dist[1004][1005], -1);
        fill(&fire[0][0], &fire[1004][1005], -1);
        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            cin >> board[i];
            if (board[i].find('@'))
            {
                idx = board[i].find('@');
                Q.push_back(make_pair(i, idx));
                dist[i][idx] = 0;
            }
        }

        // fire BFS
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '*')
                {
                    fireQ.push_back(make_pair(i, j));
                    fire[i][j] = 0;

                    while (!fireQ.empty())
                    {
                        pair<int, int> cur = fireQ.front();
                        fireQ.pop_front();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                            {
                                continue;
                            }
                            if (fire[nx][ny] != -1 || board[nx][ny] == '#')
                                continue;

                            fire[nx][ny] = min(fire[nx][ny], fire[cur.X][cur.Y] + 1);
                            fireQ.push_back(make_pair(nx, ny));
                        }
                    }
                }
            }
        }

        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop_front();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << dist[cur.X][cur.Y] + 1 << "\n";
                    return 0;
                }

                if (dist[nx][ny] != -1 || board[nx][ny] == '#')
                    continue;
                if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
                    continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                Q.push_back(make_pair(nx, ny));
            }
        }
        cout << "IMPOSSIBLE\n";
    }
}