#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    ll arr[105];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4;
    arr[8] = 5;
    arr[9] = 7;
    arr[10] = 9;

    // 설정
    for (int i = 11; i <= 100; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 5];
    }

    // 출력
    while (T--)
    {
        int input;
        cin >> input;

        cout << arr[input] << "\n";
    }
}