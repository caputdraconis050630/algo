#include "bits/stdc++.h"
#define ll long long

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> T;

	for (int i=0; i<T; i++) {
		int N;
		int arr[N];
		ll max = 0;
		
		cin >> N;
		
		for (int j=0; j<N; j++) {
			cin >> arr[j];
		}

		cout << "#" << i + 1 << " " << max << "\n";
	}
}