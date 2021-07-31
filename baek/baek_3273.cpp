#include <bits/stdc++.h>
using namespace std;

int freq[1000001];
int main()
{
    int cnt = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, tmp;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
        freq[tmp]++;
    }
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x > arr[i] && (x - arr[i] > arr[i]))
        {
            if (freq[x - arr[i]] != 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}