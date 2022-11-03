#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> dp (50001, 0x7f7f7f7f);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i=1; i<=n; i++) {
		if ((int)sqrt(i) * (int)sqrt(i) == i) dp[i] = 1;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=(int)sqrt(i); j++) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}
	cout << dp[n];
	return 0;
}