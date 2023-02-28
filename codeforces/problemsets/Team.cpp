#include "bits/stdc++.h"
using namespace std;

int N, MEM = 3, ANS = 0;
int arr[3];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> arr[0] >> arr[1] >> arr[2];
		if (count(arr, arr+3, 1) >= 2) ANS += 1;
	}
	cout << ANS << "\n";
	return 0;
}