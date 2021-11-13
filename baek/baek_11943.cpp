#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int aa, ao;
    int ba, bo;

    cin >> aa >> ao >> ba >> bo;

    int ans1 = ba + ao;
    int ans2 = aa + bo;

    ans1 > ans2 ? cout << ans2 << "\n" : cout << ans1 << "\n";
}