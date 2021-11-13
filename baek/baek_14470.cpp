#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    if (A < 0)
    {
        int tmp = abs(A);
        cout << tmp * C + E * B + D << "\n";
    }
    else if (A == 0)
    {
        cout << E * B + D << "\n";
    }
    else
    {
        int tmp = B - A;
        if (tmp <= 0)
            cout << "0\n";
        else
        {
            cout << E * tmp << "\n";
        }
    }
}