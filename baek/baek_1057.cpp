#include <iostream>
using namespace std;

int N, jimin, hansu, i;

int main(){
	cin >> N >> jimin >> hansu;

	while (++i) {
		N++, jimin++, hansu++;

		if (jimin / 2 == hansu / 2) {
			cout << i << endl;
			break;
		}

		N /= 2, jimin /= 2, hansu /= 2;
	}
}