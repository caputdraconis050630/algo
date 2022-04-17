#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a <= 1 && b <= 2)
			cout << "Yes\n";
		else if (a <= 2 && b <= 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}