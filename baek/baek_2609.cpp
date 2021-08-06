#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 1 || b == 1)
    {
        return 1;
    }
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    int gcd_result = gcd(A, B);
    int lcd_result = (A * B) / gcd_result;

    cout << gcd_result << "\n"
         << lcd_result << "\n";
}