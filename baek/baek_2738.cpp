#include "bits/stdc++.h"
using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int SUM[N][M];
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> SUM[i][j];
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			int tmp;
			cin >> tmp;
			SUM[i][j] += tmp;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << SUM[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}