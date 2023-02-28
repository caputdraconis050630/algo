#include "bits/stdc++.h"
#define ll long long
using namespace std;

int N, M, A;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> A;

	ll ans = (ll)(ceil((double)N / A)) * (ll)(ceil((double)M / A));
	cout << ans << "\n";
	return 0;
}