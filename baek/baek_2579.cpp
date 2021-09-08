#include <bits/stdc++.h>
using namespace std;

int stair[302];
int n;
int d[302][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }

    if (n == 1)
    {
        cout << stair[1];
        return 0;
    }

    d[1][1] = stair[1];
    d[1][2] = 0;
    d[2][1] = stair[2];
    d[2][2] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + stair[i];
        d[i][2] = d[i - 1][1] + stair[i];
    }

    cout << max(d[n][1], d[n][2]);
}