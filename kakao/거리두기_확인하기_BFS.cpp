#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dist[5][5];

bool OOB(int x, int y)
{
    // Check Out of Bound
    // return true => Out of Bound Happend
    return x < 0 or x > 4 or y < 0 or y > 4;
}

int chk(vector<string> board)
{
    // return true => there are people only who obeyed to rule
    // return false => there is a person who not obeyed to rule
    queue<pair<int, int>> Q;
    fill(&dist[0][0], &dist[4][5], -1);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 'O' or board[i][j] == 'X')
            {
                continue;
            }

            dist[i][j] = 0;
            Q.push(make_pair(i, j));

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (OOB(nx, ny))
                        continue;

                    if (i == nx && j == ny)
                        continue;
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                    if (dist[nx][ny] > 2)
                        continue;
                    if (board[nx][ny] == 'X')
                        continue;

                    if (board[nx][ny] == 'P')
                    {
                        return false;
                    }

                    if (board[nx][ny] == 'O' && dist[nx][ny] != 2)
                        Q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int room = 0; room < 5; room++)
    {
        answer.push_back(chk(places.at(room)));
    }

    return answer;
}