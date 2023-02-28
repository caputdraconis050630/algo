#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int T;
	string N;
	char x, y;

	cin >> T;

	for (int t=0; t<T; t++) {
		int i=0, j=0;
		string ans = "";
		cin >> N >> x >> y;
		int len = N.length();

		for (i=0; i<len; i++) {
			char c = N.at(i);

			if (c >= y) {
				ans += y;
				if (c > y) break;
			} else if (c >= x) {
				ans += x;
				if (c > x) break;
			} else {
				for (j=0; j<i; j++) {
					char pre = ans.at(i-j-1);
					if (pre == y) {
						ans[i-j-1] = x;
						i--;
						break;
					}
					ans.erase(i-j-1);
				}
				i = i - j;
				break;
			}
		}

		for (int k=0; k<len-i-1;k++) {
			ans += y;
		}
		if (ans == "") {
			cout << "#" << t+1 << " -1\n";
		} else {
			int size = ans.length();
			for (int k=0; k<size; k++) {
				if (ans[k] == '0') {
					ans.erase(k);
					size--;
					k--;
				} else {
					break;
				}
			}

			if (ans == "") {
				cout << "#" << t+1 << " -1\n";
			} else {
				cout << "#" << t+1 << " " << ans << "\n";
			}
		}
	}
	return 0;
}