#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, K;

    cin>>N>>M>>K;

    int ao = M;
    int ax = N - M;

    int bo = K;
    int bx = N - K;

    int ans = 0;
    ans += min(ao, bo);
    ans += min(ax, bx);
    cout << ans << "\n";
}
