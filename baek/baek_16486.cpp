#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    double d1, d2;
    cin >> d1 >> d2;

    double ans = 0;
    ans += 2 * d1;
    ans += M_PI * (d2 * 2);

    cout.precision(8);
    cout << ans << "\n";
}
