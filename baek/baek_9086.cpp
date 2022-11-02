#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i=0; i<T; i++) {
		string tmp;
		cin >> tmp;
		cout << tmp[0] << tmp[tmp.length() - 1] << "\n";
	}


	return 0;
}