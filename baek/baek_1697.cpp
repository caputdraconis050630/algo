#include <bits/stdc++.h>
using namespace std;

// int board[100002];
int dist[100002];
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[2] = {-1, 1};
    int N, K;
    cin >> N >> K;

    fill(dist, dist + 100002, -1);
    dist[N] = 0;
    queue<int> Q;
    Q.push(N);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 3; dir++)
        {
            int nx;
            if (dir != 2)
            {
                nx = cur + dx[dir];
            }
            else
            {
                nx = 2 * cur;
            }

            if (nx < 0 || nx > 100000)
                continue;

            if (dist[nx] == -1)
            {
                dist[nx] = dist[cur] + 1;
            }
            else
            {
                continue;
            }

            if (nx == K)
            {
                cout << dist[nx] << "\n";
                return 0;
            }

            Q.push(nx);
        }
    }

    cout << dist[K] << "\n";
}