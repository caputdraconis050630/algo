#include <bits/stdc++.h>
using namespace std;

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"};

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string board[50];

int WB_cnt(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != WB[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int BW_cnt(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != BW[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int min = 65;

    // 입력 시작
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    // 입력 끝

    // 순회하면서 카운트 시작
    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            if (min > BW_cnt(i, j))
                min = BW_cnt(i, j);
            if (min > WB_cnt(i, j))
                min = WB_cnt(i, j);
        }
    }

    cout << min << "\n";
}