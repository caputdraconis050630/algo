#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int tmp;
        cin >> tmp;
        ans += tmp;
    }

    int m = ans / 60;
    int s = ans % 60;

    cout << m << "\n"
         << s << "\n";
}