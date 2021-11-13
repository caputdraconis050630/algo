#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int n = 0, m = 0;

    while (N--)
    {
        if (K >= M)
        {
            K -= M;
            n++;
        }
        else
        {
            m = K;
            break;
        }
    }

    cout << n << " " << m << "\n";
}