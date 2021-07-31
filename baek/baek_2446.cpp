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
        for (int k = 0; k < 2 * (N - i) - 1; k++)
            cout << "*";
        cout << "\n";
    }
    for (int i = 0; i < N - 1; i++)
    {
        //  0 1 2 3
        for (int k = 0; k < N - i - 2; k++)
            cout << " ";
        for (int k = 0; k < 2 * i + 3; k++)
            cout << "*";
        cout << "\n";
    }
}