#include <bits/stdc++.h>

// 생략 가능(gcc)
#define and &&
#define or ||

using namespace std;

// 기준점 기준 상하좌우 체크(맨해튼 거리 1)
int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, -1, 0, 1};

// 기준점 기준 대각선 체크(맨해튼 거리 2)
int dx2[4] = {1, 1, -1, -1};
int dy2[4] = {1, -1, -1, 1};

// 기준점 기준 직선거리 2 체크(맨해튼 거리 2)
int dx3[4] = {-2, 0, 2, 0};
int dy3[4] = {0, -2, 0, 2};

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

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 'X' or board[i][j] == 'O')
                continue;

            // 여기부터는 board[i][j] == 'P"

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx1[dir];
                int ny = j + dy1[dir];

                if (OOB(nx, ny))
                    continue;
                if (board[nx][ny] == 'P')
                    return false;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx2[dir];
                int ny = j + dy2[dir];

                if (OOB(nx, ny))
                    continue;

                if (board[nx][ny] == 'P')
                {
                    // 거쳐오는 길에 파티션이 있나 체크
                    if (board[i][ny] != 'X' or board[nx][j] != 'X')
                        return false;
                }
            }

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx3[dir];
                int ny = j + dy3[dir];

                if (OOB(nx, ny))
                    continue;
                if (board[nx][ny] == 'P')
                {
                    // 전 테이블에 파티션이 있는 경우 체크
                    if (board[i + dx1[dir]][j + dy1[dir]] != 'X')
                        return false;
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