#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll d = 1000000007;
long long arr1[500001];
long long arr2[500001];
ll ans = 0;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin >> arr1[0];
    arr2[0] = arr1[0];

    for (int i = 1; i < N; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr2[i - 1] + arr1[i];
    }

    for (int i = 1; i < N; i++)
    {
        ans += (ll)arr1[i] * arr2[i - 1] % d;
        ans %= d;
    }

    cout << ans << "\n";
}