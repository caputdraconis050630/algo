// https://www.acmicpc.net/problem/10871
#include <bits/stdc++.h>
using namespace std;

int N, X, t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    while (N--)
    {
        cin >> t;
        if (t < X)
            cout << t << ' ';
    }

    return 0;
}