#include <bits/stdc++.h>
using namespace std;

int arr[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    // 1 1 1 / 1 2 / 2 1 / 3

    for (int i = 4; i < 11; i++)
    {
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }

    while (T--)
    {
        int tmp;
        cin >> tmp;
        cout << arr[tmp] << "\n";
    }
    return 0;
}