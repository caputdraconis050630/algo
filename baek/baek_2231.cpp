#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum;
    int tmp;

    for (int i = 1; i <= N; i++)
    {
        tmp = i;
        sum = tmp;

        while (tmp != 0)
        {
            sum += (tmp % 10);
            tmp /= 10;
        }

        if (sum == N)
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << "0\n";
}