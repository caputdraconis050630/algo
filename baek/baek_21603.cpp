#include <bits/stdc++.h>
using namespace std;

int N, K, cnt, tmp;

int main(void)
{
	cin >> N >> K;
	vector<int> hoit;
	for (int i = 1; i <= N; i++)
	{
		tmp = i % 10;
		if ((tmp != (2 * K) % 10) && (tmp != K % 10))
		{
			cnt += 1;
			hoit.push_back(i);
		}
	}
	cout << cnt << "\n";
	if (hoit.empty())
		cout << "\n";
	else
	{
		for (int i = 0; i < hoit.size(); i++)
		{
			cout << hoit.at(i) << " ";
		}
		cout << "\n";
	}
}