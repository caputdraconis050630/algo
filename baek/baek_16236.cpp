#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
int board[25][25];
int vis[25][25];
int shark_size = 2; // 아기 상어 사이즈(Default 2)
int eat = 0;        // 지금 사이즈에서 아기상어가 먹은 물고기의 수
int ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

deque<pair<int, int> > D;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    fill(&vis[0][0], &vis[24][24], 0); // 초기화
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                D.push_back(make_pair(i, j));
                vis[i][j] = 1;
                board[i][j] = 0;
            }
        }
    }

    // while 반복 한 번당 한 마리 먹음
    while (1)

    {
        while (!D.empty())
        {
            pair<int, int> cur = D.front();
            D.pop_front();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                if (board[nx][ny] > shark_size)
                    continue;
                if (vis[nx][ny])
                    continue;

                D.push_back(make_pair(nx, ny));
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            }
        }

        int time = INT_MAX; // 그냥 큰 수~
        pair<int, int> now;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                    continue;
                if (board[i][j] >= shark_size) // 같은 크기도 먹지 못함
                    continue;
                if (vis[i][j] && vis[i][j] < time)
                {
                    time = vis[i][j];
                    now = make_pair(i, j);
                }
            }
        }
        if (time == INT_MAX)
            break;
        D.push_back(now);
        ans += time - 1;
        fill(&vis[0][0], &vis[24][24], 0); // 초기화
        vis[now.X][now.Y] = 1;
        board[now.X][now.Y] = 0; // 물고기 쥬금
        eat++;
        // 사이즈업
        if (eat == shark_size)
        {
            shark_size++;
            eat = 0;
        }
    }
    cout << ans << "\n";
}