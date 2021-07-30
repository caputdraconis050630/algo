#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0, tmp;
    ;
    int M = 0; // 민식
    int Y = 0; // 영식
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        M += tmp / 60;
        Y += tmp / 30;
    }

    M = (N + M) * 15;
    Y = (N + Y) * 10;

    if (M == Y)
        cout << "Y M " << M;
    else
    {
        if (M > Y)
        {
            cout << "Y " << Y;
        }
        else
        {
            cout << "M " << M;
        }
    }
}