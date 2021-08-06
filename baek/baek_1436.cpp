#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt = 0;
    int title = 665; // 초기값
    cin >> N;
    string S;

    while (++title)
    {
        S = to_string(title);

        if (S.find("666") != -1)
        { // 찾았다!
            ++cnt;
        }

        if (cnt == N)
        {
            cout << title << endl;
            break;
        }
    }

    return 0;
}   