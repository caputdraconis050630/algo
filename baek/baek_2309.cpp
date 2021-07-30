#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int arr[9];
    ;
    bool chk = false;
    int i, k;
    for (i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (i = 0; i < 9; i++)
    {
        for (k = 8; k > i; k--)
        {
            if (sum - (arr[i] + arr[k]) == 100)
            {
                chk = true;
                break;
            }
        }
        if (chk)
            break;
    }

    arr[i] = 0;
    arr[k] = 0;

    sort(arr, arr + 9);
    for (int q = 0; q < 9; q++)
    {
        if (arr[q] != 0)
        {
            cout << arr[q] << "\n";
        }
    }
}