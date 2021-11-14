#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll arr[1001];
ll dist = 4;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    arr[1] = 1;
    arr[2] = 3;

    cin >> n;

    for (int i = 3; i <= 1000; i++)
    {
        arr[i] = arr[i - 2] + dist;
        arr[i] %= 10007;
        dist *= 2;
        dist %= 10007;
    }

    cout << arr[n];
}