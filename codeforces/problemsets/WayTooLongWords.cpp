#include "bits/stdc++.h"
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string t;
		cin >> t;
		int len = t.length();
		if (len > 10) {
			cout << t[0] << len-2 << t[len-1] << "\n";
		} else {
			cout << t << "\n";
		}
	}
}