#include "bits/stdc++.h"
using namespace std;

int N, K, ANS = 0, KTH;
vector<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i=0; i<N; i++) {
		int score;
		cin >> score;
		q.push_back(score);

		if (i+1 == K)
			KTH = score;
	}
	for (int i=0; i<N; i++) {
		if (q[i] >= KTH) {
			if (q[i] > 0) ANS += 1;	
		}
		else
			break;
	}
		
	
	cout << ANS << "\n";
}