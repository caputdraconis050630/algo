#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;
    int sum = 0;

    for (int i = 4; i >= 0; i--)
    {
        int tmp = n[i] - '0';

        int ans = pow(tmp, 5);
        sum += ans;
    }

    cout << sum << "\n";
}