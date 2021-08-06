#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int result;
    if (K == 0 || K == N)
    {
        result = 1;
    }
    else
    {
        result = factorial(N) / (factorial(K) * factorial(N - K));
    }
    cout << result << "\n";
}