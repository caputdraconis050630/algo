#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int arr[9];
    int i, k;

    bool chk = false;
    for (i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);

    for (i = 0; i < 9; i++)
    {
        for (k = 8; k > i; k--)
        {
            if (sum - (arr[i] + arr[k]) == 100)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j == i || j == k)
                        continue;
                    else
                    {
                        cout << arr[j] << "\n";
                    }
                }
                return 0;
            }
        }
    }
}