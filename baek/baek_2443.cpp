#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < i; k++)
            cout << " ";
        for (int k = 0; k < (2 * N - 2 * i) - 1; k++)
            cout << "*";

        cout << "\n";
    }
}