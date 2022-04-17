#include <bits/stdc++.h>
using namespace std;

int N;
double P, C, tmp;

int main(void)
{
	cin >> N;
	while (N--)
	{
		cout.precision(10);
		cin >> P >> C;
		tmp = 100 * P;
		tmp /= (C + 100);
		cout << tmp;
		cout << "\n";
	}
	return (0);
}