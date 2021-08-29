// Unsolve

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int max = 0;
    cin >> N >> M;

    int len[N];
    for (int i = 0; i < N; i++)
    {
        cin >> len[i];
        if (max < len[i])
            max = len[i];
    }
    int tmp;
    int sum = 0;
    for (int i = max; i >= 0; i--)
    {
        sum = 0;
        for (int j = 0; j < N; j++)
        {
            tmp = len[j] - i;
            if (tmp >= 0)
            {
                sum += tmp;
            }
        }
        if (sum >= M)
        {
            cout << i << "\n";
            return 0;
        }
    }
}