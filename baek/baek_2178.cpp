#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102]; // 거리 저장할 변수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    queue<pair<int, int> > q;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
    {
        fill(dist[i], dist[i] + M, -1);
    }

    q.push(make_pair(0, 0));
    dist[0][0] = 0;

    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = tmp.X + dx[dir];
            int ny = tmp.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
            {
                continue;
            }

            dist[nx][ny] = dist[tmp.X][tmp.Y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    cout << dist[N - 1][M - 1] + 1<< "\n";
}