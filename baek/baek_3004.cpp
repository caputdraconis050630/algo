#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    if (N % 2 == 0)
    {
        int tmp = N / 2 + 1;
        cout << tmp * tmp << "\n";
    }
    else
    {
        int tmp = N / 2;
        cout << (tmp + 1) * (tmp + 2) << "\n";
    }
}