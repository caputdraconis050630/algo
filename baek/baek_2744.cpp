#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	int gap = 'a' - 'A';
	cin >> input;
	size_t len = input.length();
	
	for (int i=0; i<len; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			cout << char(input[i] + gap);
		} else if (input[i] >= 'a' && input[i] <= 'z') {
			cout << char(input[i] - gap);
		} else {
			cout << input[i];
		}
	}
	cout << "\n";
	return 0;
}