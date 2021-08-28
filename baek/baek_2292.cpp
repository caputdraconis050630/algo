#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 1;

    if (N == 1)
    {
        cout << cnt;
        return 0;
    }

    N--;

    while (true)
    {
        if (N > 6 * cnt)
        {
            N -= 6 * cnt;
            cnt++;
        }
        else
        {
            break;
        }
    }

    cout << cnt + 1 << "\n";
}