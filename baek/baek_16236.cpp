#include <bits/stdc++.h>
#define first X
#define second Y
using namespace std;

int N;
int size = 2; // 아기 상어의 기본 사이즈 2
int eat = 0; // 현재 사이즈에서 먹은 마리수
int board[21][21];
int visit[21][21];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> Q;
    fill(&visit[0][0], &visit[20][21], -1); // Not visit -> -1
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 9)
            {
                Q.push(make_pair(i, j));
                visit[i][j] = 0;
            }
        }
    }

    pair<int, int> cur;
    while (!Q.empty)
    {
        cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (board[nx][ny] == 0)
            {
                // 빈칸일 때
                continue;
            }

            if (board[nx][ny] > size)
            {
                // 아기 상어의 사이즈보다 클 경우 continue
                continue;
            }

            
        }
    }



    // 결과 출력
    int MX = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] > MX)
                MX = visit[i][j];
        }
    }

    cout << MX << '\n';
    return 0;
}