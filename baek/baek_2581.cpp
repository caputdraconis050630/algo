#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min, max;
    cin >> min >> max;
    int sum = 0;
    bool prime[max + 1];
    fill_n(prime, max + 1, 1);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * 2; j <= max; j++)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = min; i <= max; i++)
    {
        if (prime[i] == true)
        {
            cout << i << "\n";
        }
    }
}