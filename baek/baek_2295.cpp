#include <bits/stdc++.h>
using namespace std;

int n;
int x[1005];
vector<int> two;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x, x + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            two.push_back(x[i] + x[j]);
        }
    }

    sort(two.begin(), two.end());

    // 맨 뒤와 맨 앞에서부터 도는 이유 => 가장 큰 d를 찾기 위해서
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (binary_search(two.begin(), two.end(), x[i] - x[j]))
            {
                cout << x[i];
                return 0;
            }
        }
    }
}