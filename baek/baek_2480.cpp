#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, tmp;
    cin >> a >> b >> c;
    int sum = 0;
    if (a == b && b == c)
    {
        // 세 개의 값이 다 똑같을 때
        sum = 10000 + 1000 * a;
    }
    else if (a == b || a == c)
    {
        // a가 중복값일 때
        sum = 1000 + 100 * a;
    }
    else if (b == c)
    {
        // b가 중복값일 때
        sum = 1000 + 100 * b;
    }
    else
    {
        // 모두 다를 때
        tmp = max({a, b, c});
        sum = tmp * 100;
    }
    cout << sum;
}