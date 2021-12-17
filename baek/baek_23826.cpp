#include <bits/stdc++.h>
using namespace std;

int N;
int tx, ty, tE;

int x[1001], y[1001], E[1001]; // x, y, Energy

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    cin >> tx >> ty >> tE;

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> E[i];
    }

    for (int i = 0; i < N; i++)
    {
        int pub = max(0, tE - (abs(tx - x[i]) + abs(ty - y[i])));
        for (int j = 0; j < N; j++)
        {
            int tmp = max(0, E[j] - (abs(x[j] - x[i]) + abs(y[j] - y[i])));
            pub -= tmp;
        }
        ans = max(ans, pub);
    }

    if (ans == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << "\n";
}