#include <bits/stdc++.h>
using namespace std;

int n, k;
int x[10005];

bool solve(long long mid)
{
    long long cur = 0;

    for (int i = 0; i < k; i++)
    {
        cur += x[i] / mid;
    }

    return cur >= n;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
        cin >> x[i];

    long long st = 1;
    long long en = 0x7fffffff;

    while (st < en)
    {
        int mid = (st + en + 1) / 2;

        if (solve(mid))
        {
            st = mid;
        }
        else
        {
            en = mid - 1;
        }
    }

    cout << st << "\n";
}