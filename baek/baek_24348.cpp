#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << max(b * c + a, max(a * b + c, a * c + b));
	return (0);
}