#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int sh, sm, l;
    cin >> sh >> sm >> l;

    int lh = l / 60;
    int lm = l % 60;

    if (sm + lm >= 60)
    {
        // hour + 1
        cout << (sh + lh + 1) % 24 << " " << sm + lm - 60 << "\n";
    }

    else
    {
        cout << (sh + lh) % 24 << " " << sm + lm << "\n";
    }
}