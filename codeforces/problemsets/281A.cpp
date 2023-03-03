#include "bits/stdc++.h"
using namespace std;

int GAP = 'a' - 'A';

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	if (input[0] >= 'a' && input[0] <= 'z') {
		input[0] -= GAP;
	}

	cout << input << "\n";
	return 0;
}