#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int tc;
    int A, B;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> A >> B;
        if (A >= 10 || B >= 10)
        {
            cout << -1 << "\n";
            break;
        }
        cout << A * B << "\n";
    }
}