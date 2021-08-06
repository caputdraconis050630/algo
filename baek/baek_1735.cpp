#include <bits/stdc++.h>
using namespace std;

// 유클리드 호제법
int gcd(int a, int b)
{
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

    int A_up, A_down;
    int B_up, B_down;
    int res_up, res_down;
    cin >> A_up >> A_down;
    cin >> B_up >> B_down;

    res_up = A_up * B_down + B_up * A_down;
    res_down = A_down * B_down;

    int gcd_num = gcd(res_up, res_down);

    cout << res_up / gcd_num << " " << res_down / gcd_num << "\n";
}