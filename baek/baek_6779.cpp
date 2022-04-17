#include <bits/stdc++.h>
using namespace std;

int h, M;

int main(void)
{
	cin >> h >> M;
	for (int i = 1; i <= M; i++)
	{
		if (((-6) * pow(i, 4) + h * pow(i, 3) + 2 * pow(i, 2) + i) <= 0)
		{
			cout << "The balloon first touches ground at hour: " << i << "\n";
			return (0);
		}
	}
	cout << "The balloon does not touch ground in the given time.\n";
}