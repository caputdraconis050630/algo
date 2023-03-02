#include "bits/stdc++.h"
using namespace std;

int cnt[3] = {0, };

void printResult();

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string op;
	cin >> op;
	for (int i=0; op[i]; i++) {
		if (op[i] == '+') continue;
		cnt[op[i] - '1']++;
	}

	printResult();
	return 0;
}

void printResult() {
	bool flag = false; // 처음 출력할 때
	while (cnt[0]--) {
		if (!flag)
			flag = true;
		else
			cout << "+";
		cout << "1";
	}
	while (cnt[1]--) {
		if (!flag)
			flag = true;
		else
			cout << "+";
		cout << "2";
	}
	while (cnt[2]--) {
		if (!flag)
			flag = true;
		else
			cout << "+";
		cout << "3";
	}
	cout << "\n";
}