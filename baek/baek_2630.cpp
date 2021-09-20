#include <bits/stdc++.h>
using namespace std;

bool paper[135][135];
int white_color_paper = 0;
int blue_color_paper = 0;

void paper_count(int x, int y, int N)
{
    bool cur = paper[x][y];
    bool check = false;

    // 조건 만족했는지 체크 -> 만족 : check = false , 불만족 : check = true
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (paper[x + i][y + j] != cur)
            {
                i = N;
                j = N; // break
                check = true;
            }
        }
    }

    if (check)
    {
        // 나눠야 하는 상황
        paper_count(x, y, N / 2);
        paper_count(x + (N / 2), y, N / 2);
        paper_count(x, y + (N / 2), N / 2);
        paper_count(x + (N / 2), y + (N / 2), N / 2);
    }
    else
    {
        // 한 색으로만 이루어져 있음 => 조건 만족
        if (cur == false)
        {
            white_color_paper++;
        }
        else
        {
            blue_color_paper++;
        }
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    paper_count(0, 0, n);

    cout << white_color_paper << "\n"
         << blue_color_paper << "\n";
}