#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int max = 0;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 0; i < N - 2; i++)
    {
        for (int k = i + 1; k < N - 1; k++)
        {
            for (int q = k + 1; q < N; q++)
            {
                int tmp = arr[i] + arr[k] + arr[q];
                if (tmp > max && tmp <= M)
                {
                    max = tmp;
                }
            }
        }
    }

    cout << max << "\n";
}