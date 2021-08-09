#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int K, N;
int lan_cable[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max = 0;
    int mid;
    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        cin >> lan_cable[i];
        if (max < lan_cable[i])
            max = lan_cable[i];
    }

    int start = 1;
    int end = max;

    int ans = 0;
    while (start <= end)
    {
        int cnt = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < K; i++)
        {
            cnt += lan_cable[i] / mid;
        }

        if (cnt < N)
        {
            end = mid - 1;
        }
        else if (cnt == N)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            // if(cnt > N)
            start = mid + 1;
        }
    }
    cout << ans << "\n";
}