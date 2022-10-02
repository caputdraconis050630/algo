#include "bits/stdc++.h"
using namespace std;

long long N, ans = 0;
string pwd;

void input() {
	cin >> N;
	cin >> pwd;
	return;
}

void output() {
	cout << ans << endl;
	return;
}

void calculate() {
	char q = 'a';
	N -= 1;
	for(int i = 0; i < pwd.length(); i++) {
		int diff = pwd[i] - q;
		if (diff > 0)
			ans += diff * 26 * (pow(26, N) - 1) / 25 + diff;
		ans += 1;
		N -= 1;
	}
}

int main() {
	// 입력
	input();
	// 계산
	calculate();
	// 출력
	output();
	return 0;
}