#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m, p;
	int cnt = 0;
	int sum;
	cin >> n >> m >> p;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum = (i + j) * 2;
			if (sum >= p)
				cnt += (n - i + 1) * (m - j + 1);
		}
	}
	cout << cnt << "\n";
}