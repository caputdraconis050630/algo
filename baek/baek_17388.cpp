#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int S, K, H;
    cin >> S >> K >> H;

    if (S + K + H < 100)
    {
        int tmp = min({S, K, H});
        if (tmp == S)
        {
            cout << "Soongsil\n";
        }
        else if (tmp == K)
        {
            cout << "Korea\n";
        }
        else
        {
            cout << "Hanyang\n";
        }
    }
    else
    {
        cout << "OK\n";
    }
}
