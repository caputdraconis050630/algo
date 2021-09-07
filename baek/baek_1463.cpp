#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // fill(arr, arr + 1000005, INT_MAX);
    cin >> n;

    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0)
        {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }

    cout << arr[n] << "\n";
    return 0;
}