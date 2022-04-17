#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	long long sum;
	int C, W, L, P;

	cin >> C >> W >> L >> P;
	while (!(C == 0 && W == 0 && L == 0 && P == 0))
	{
		sum = C;
		sum = pow(sum, W);
		sum = pow(sum, L);
		sum = pow(sum, P);
		cout << sum << "\n";
		cin >> C >> W >> L >> P;
	}
}