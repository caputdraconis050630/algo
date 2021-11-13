#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int phy, che, lif, ear, his, pla;
    cin >> phy >> che >> lif >> ear >> his >> pla;

    int ans = 0;
    ans = phy + che + lif + ear + his + pla;
    ans -= min({phy, che, lif, ear});

    ans -= min(his, pla);

    cout << ans << "\n";
}