#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
stack<ll> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0;
    ll sum = 0;

    cin >> n;
    vector<ll> h(n);
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
        while (!s.empty() && s.top() <= h[i])
            s.pop();
        s.push(h[i]);
        sum = sum + s.size() - 1;
    }
    cout << sum << endl;
    return 0;
}
