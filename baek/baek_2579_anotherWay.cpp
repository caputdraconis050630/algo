#include <bits/stdc++.h>
using namespace std;

int stair[302];
int d[302];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> stair[i];
        sum += stair[i];
    }

    d[1] = stair[1];
    d[2] = stair[2];
    d[3] = stair[3];

    for (int i = 4; i <= n; i++)
    {
        d[i] = stair[i] + min(d[i - 2], d[i - 3]);
    }

    cout << sum - min(d[n - 1], d[n - 2]) << "\n";
}