#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int w, h;
char board[1005][1005];
int dist[1005][1005];
int fire[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool flag;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    deque<pair<int, int> > Q;
    deque<pair<int, int> > fireQ;

    while (t--)
    {

        flag = false;
        memset(fire, -1, sizeof(fire));
        memset(dist, -1, sizeof(dist));
        cin >> w >> h;
        Q.clear();
        fireQ.clear();

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> board[i][j];

                if (board[i][j] == '@')
                {
                    Q.push_back(make_pair(i, j));
                    dist[i][j] = 0;
                }
                else if (board[i][j] == '*')
                {
                    fireQ.push_back(make_pair(i, j));
                    fire[i][j] = 0;
                }
            }
        }

        // fire BFS
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
                {
                    continue;
                }

                fireQ.push_back(make_pair(nx, ny));
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            }
        }

        // man BFS
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
                    flag = true;
                    break;
                }

                if (dist[nx][ny] != -1 || board[nx][ny] == '#')
                    continue;
                if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
                    continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                Q.push_back(make_pair(nx, ny));
            }

            if(flag){
                break;
            }
        }
        if(!flag){
            cout << "IMPOSSIBLE\n";
        }
        
    }
}