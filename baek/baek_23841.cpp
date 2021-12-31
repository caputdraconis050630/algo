#include <bits/stdc++.h>
using namespace std;

int N, M;
string board[51];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int center = M / 2;

    // l2r
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < center; column++)
        {
            if (board[row][column] != '.')
            {
                board[row][M - column - 1] = board[row][column];
            }
        }
    }
    // r2l
    for (int row = 0; row < N; row++)
    {
        for (int column = center; column < M; column++)
        {
            if (board[row][column] != '.')
            {
                board[row][M - column - 1] = board[row][column];
            }
        }
    }

    // 출력
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < M; column++)
        {
            cout << board[row][column];
        }
        cout << "\n";
    }
}