#include <bits/stdc++.h>
using namespace std;

const int MX = 2 * 1e5 + 5;
int n, c;
int x[MX];

int solution()
{
    int r = x[n - 1]; // 가장 큰 좌표를 가진 집의 좌표
    int l = 1;        // 공유기 사이의 거표
    int ans = 0;

    while (l <= r)
    {
        int cnt = 1;
        int mid = (r + l) / 2;

        int start = x[0];

        for (int i = 1; i < n; i++)
        {
            if (x[i] - start >= mid)
                start = x[i], cnt++;
        }
        if (cnt >= c)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x, x + n);

    cout << solution() << "\n";
}