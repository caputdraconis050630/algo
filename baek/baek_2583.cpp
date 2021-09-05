#include <bits/stdc++.h>
using namespace std;

bool board[102][102];
bool vis[102][102];

#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K; // M이 세로, N이 가로
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    cin >> M >> N >> K;

    queue<pair<int, int> > Q;
    vector<int> area_v;

    for (int i = 0; i < K; i++)
    {
        int fir_x, fir_y, sec_x, sec_y;
        cin >> fir_x >> fir_y >> sec_x >> sec_y;

        for (int j = fir_y; j < sec_y; j++)
        {
            for (int k = fir_x; k < sec_x; k++)
            {
                board[j][k] = true;
            }
        }
    }
    // Checking 
    // for(int i = 0;i<M;i++){
    //     for(int j =0;j<N;j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == true || vis[i][j] == true)
                continue;
            int area = 1;
            vis[i][j] = true;
            Q.push(make_pair(i, j));

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                    {
                        continue;
                    }
                    if (vis[nx][ny] == true || board[nx][ny] == true)
                    {
                        continue;
                    }
                    vis[nx][ny] = true;
                    area++;
                    Q.push(make_pair(nx, ny));
                }
            }

            area_v.push_back(area);
        }
    }
    sort(area_v.begin(), area_v.end());

    cout << area_v.size() << "\n";
    for (int i = 0; i < area_v.size(); i++)
    {
        cout << area_v.at(i) << " ";
    }
}