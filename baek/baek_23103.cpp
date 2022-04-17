#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N, tmp_x = -9999, tmp_y = -9999, x, y;
	int dist = 0;
	cin >> N;
	while (N--)
	{
		cin >> x >> y;
		if (tmp_x >= -100 && tmp_y >= -100)
			dist += abs(x - tmp_x) + abs(y - tmp_y);
		tmp_x = x;
		tmp_y = y;
	}
	cout << dist << "\n";
}