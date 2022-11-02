#include "bits/stdc++.h"
using namespace std;

bool checked[31] = {false, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=1; i <= 28; i++) {
		int tmp;
		cin >> tmp;
		checked[tmp] = true;
	}

	for(int i=1; i<= 30; i++) {
		if (!checked[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}