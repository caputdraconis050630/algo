#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;
    ll ansX, ansY;
    ansX = A * P;
    if (P >= C)
    {
        int d = P - C;
        ansY = B + D * d;
    }
    else
    {
        ansY = B;
    }

    cout << min(ansX, ansY) << "\n";
}