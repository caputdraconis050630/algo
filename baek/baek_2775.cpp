#include <bits/stdc++.h>
using namespace std;

int getNum(int a, int b)
{
    if (b == 1)
        return 1;
    if (a == 0)
        return b;
    return (getNum(a - 1, b) + getNum(a, b - 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> k >> n;
        cout << getNum(k, n) << '\n';
    }
}