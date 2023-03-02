#include "bits/stdc++.h"
using namespace std;

int ANS = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			int tmp;
			cin >> tmp;

			if (tmp != 0) {
				ANS += abs(2 - i);
				ANS += abs(2 - j);
			}
		}
	}

	cout << ANS << "\n";
}