#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long A, B;
    cin >> A >> B;
    if (A > B)
        swap(A, B);
        
    if (A == B)
        cout << "0"
             << "\n";
    else
        cout << B - A - 1 << "\n";

    for (unsigned long long i = A + 1; i < B; i++)
    {
        cout << i << " ";
    }
}
