#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int A, I;

    cin >> A >> I;

    if (I == 0)
    {
        cout << "0\n";
        return 0;
    }
    cout << A * (I - 1) + 1 << "\n";
}