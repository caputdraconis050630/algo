#include "bits/stdc++.h"
using namespace std;

int n, ans=0;

void bfs(int q) {
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i=1; i * i <= n; i++) {
		ans += 1;
		bfs(i);
		ans -= 1;
	}

	return 0;
}