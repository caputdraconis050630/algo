#include <bits/stdc++.h>
using namespace std;

int arr[41][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    arr[0][0] = 1;
    arr[0][1] = 0;

    arr[1][0] = 0;
    arr[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
        arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
    }

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        cout << arr[N][0] << " " << arr[N][1] << "\n";
    }
}