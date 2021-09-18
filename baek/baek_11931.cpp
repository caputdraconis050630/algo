#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1000000;

bool board[2 * MX + 1];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        board[tmp + MX] = true;
    }

    int cnt = 0;
    int high = 2 * MX;
    for (int i = high; i >= 0; i--)
    {
        if (board[i])
        {
            cout << i - MX << "\n";
            cnt++;
        }

        if (cnt == N)
        {
            break;
        }
    }
    return 0;
}