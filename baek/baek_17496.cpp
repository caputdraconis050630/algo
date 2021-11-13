#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, T, C, P;
    cin >> N >> T >> C >> P;

    ll days = (N - 1) / T;
    cout << C * P * days << "\n";
}