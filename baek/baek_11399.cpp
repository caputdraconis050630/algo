#include <bits/stdc++.h>
using namespace std;

int x[1005];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x, x + n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i] * (n - i);
    }

    cout << sum << "\n";
}