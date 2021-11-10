#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2190][2190];
int ans[3]; // 정답을 채울 배열
void Cnt(int sx, int sy, int size)
{
    int cnt_arr[3] = {0, 0, 0};
    for (int i = sx; i < sx + size; i++)
    {
        for (int j = sy; j < sy + size; j++)
        {
            if (paper[i][j] == -1)
                cnt_arr[0]++;
            else if (paper[i][j] == 0)
                cnt_arr[1]++;
            else
                cnt_arr[2]++;
        }
    }

    if (cnt_arr[0] == 0 and cnt_arr[1] == 0)
    {
        // 1만 있는 상황
        ans[2]++;
    }
    else if (cnt_arr[1] == 0 and cnt_arr[2] == 0)
    {
        // -1만 있는 상황
        ans[0]++;
    }
    else if (cnt_arr[0] == 0 and cnt_arr[2] == 0)
    {
        // 0만 있는 상황
        ans[1]++;
    }
    else
    {
        // 하나의 수만 있는 상황이 아닐 때
        int t = size / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Cnt(sx + i * t, sy + j * t, t);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    Cnt(0, 0, N);

    for (auto c : ans)
    {
        cout << c << " ";
    }
    return 0;
}