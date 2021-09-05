#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[26];
bool vist[26][26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    cin >> N;

    queue<pair<int, int> > Q;
    vector<int> area;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!vist[i][j] && board[i].at(j) == '1')
            {
                int area_cnt = 1;
                vist[i][j] = true;
                Q.push(make_pair(i, j));

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        {
                            continue;
                        }
                        if (vist[nx][ny] || board[nx].at(ny) == '0')
                            continue;

                        vist[nx][ny] = true;
                        area_cnt++;
                        Q.push(make_pair(nx, ny));
                    }
                }

                area.push_back(area_cnt);
            }
        }
    }
    cout << area.size() << "\n";
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++)
    {
        cout << area.at(i) << "\n";
    }
}