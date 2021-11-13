#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int S = 0, T = 0;
    for (int i = 0; i < 4; i++)
    {
        int tmp;
        cin >> tmp;
        S += tmp;
    }
    for (int i = 0; i < 4; i++)
    {
        int tmp;
        cin >> tmp;
        T += tmp;
    }

    S > T ? cout << S << "\n" : cout << T << "\n";
}