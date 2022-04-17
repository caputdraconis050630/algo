#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
	int flag = 1;

	cin >> t;

	while (t--)
	{
		flag = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int tmp_l;
			int tmp_r;
			cin >> tmp_l >> tmp_r;
			if (tmp_l + tmp_r != n)
				flag = 0;
		}
		if (flag)
			cout << "no\n";
		else
			cout << "yes\n";
	}
	return (0);
}