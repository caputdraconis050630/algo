#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int t, arr[4];
	int ans[3], tmp;
	cin >> t;

	while (t--)
	{
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 0;

		for (int i = 0; i <= 1; i++)
		{
			for (int j = i + 1; j <= 2; j++)
			{
				for (int k = j + 1; k <= 3; k++)
				{
					int max_len = max(arr[i], max(arr[j], arr[k]));
					int else_square = pow(arr[i], 2) + pow(arr[j], 2) + pow(arr[k], 2) - pow(max_len, 2);
					int sum = arr[i] + arr[j] + arr[k];
					if (sum > 2 * max_len)
					{
						// Check 직각
						if (else_square == pow(max_len, 2))
							ans[0] += 1;
						// Check 예각
						if (else_square > pow(max_len, 2))
							ans[1] += 1;
						// Check 둔각
						if (else_square < pow(max_len, 2))
							ans[2] += 1;
					}
				}
			}
		}
		cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
	}	
}