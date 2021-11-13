#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int d; // 일의 자리 숫자
    int ans = 0;
    cin >> d;
    for (int i = 0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == d)
            ans++;
    }
    cout << ans << "\n";
}