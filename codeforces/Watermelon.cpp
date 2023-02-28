#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int N;
	cin >> N;
	N == 2 ? cout << "NO\n" : (N % 2 == 0 ? cout << "YES\n" : cout << "NO\n");
	return 0;
}