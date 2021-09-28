#include <bits/stdc++.h>
using namespace std;

typedef struct tomato
{
    int x, y, z;
} tomato;

int M, N, H;
int board[102][102][102];
int days[102][102][102];
queue<tomato> Q;
bool flag = false;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> board[i][j][k];
                /*
                    if board[i][j][k] == -1
                        not exist
                    if board[i][j][k] == 0
                        not riped
                    if board[i][j][k] == 1
                        riped
                    
                */
                days[i][j][k] = -1;

                if (board[i][j][k] == 1)
                {
                    tomato tmp;
                    tmp.x = i;
                    tmp.y = j;
                    tmp.z = k;
                    days[i][j][k] = 0;
                    Q.push(tmp);
                }
                else if (board[i][j][k] == 0)
                {
                    flag = true;
                }
            }
        }
    }

    if (!flag)
    {
        cout << "0\n";
        return 0;
    }

    while (!Q.empty())
    {
        tomato cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            tomato nxt;
            nxt.x = cur.x + dx[dir];
            nxt.y = cur.y + dy[dir];
            nxt.z = cur.z + dz[dir];

            // 범위 필터링
            if (nxt.x < 0 || nxt.x >= H || nxt.y < 0 || nxt.y >= N || nxt.z < 0 || nxt.z >= M)
            {
                continue;
            }

            if (days[nxt.x][nxt.y][nxt.z] != -1)
            {
                // 이미 방문한 적이 있다면 continue
                continue;
            }

            if (board[nxt.x][nxt.y][nxt.z] != 0)
            {
                // 그 칸이 이미 익은 토마토이거나, 토마토가 존재하지 않을 때 continue
                continue;
            }

            days[nxt.x][nxt.y][nxt.z] = days[cur.x][cur.y][cur.z] + 1;
            board[nxt.x][nxt.y][nxt.z] = 1;
            Q.push(nxt);
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[i][j][k] == 0)
                {
                    cout << "-1\n";
                    return 0;
                }

                if (ans < days[i][j][k])
                    ans = days[i][j][k];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}