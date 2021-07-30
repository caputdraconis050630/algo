#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, sum = 0;
    int arr[95] = {
        // 배열 초기화 필수
        0,
    };
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        sum += t;
        arr[t]++;
    }

    int c = 0;
    for (t = 0; c < 3; t++)
    {
        c += arr[t];
    }
    cout << sum / 5 << "\n"
         << --t;
}