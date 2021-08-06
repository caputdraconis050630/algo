#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input[8];
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> input[i];
    }

    if (input[0] == 1)
    {
        // ascending 경우일 때
        for (int i = 1; i < 8; ++i)
        {
            if (input[i] == i + 1)
            {
                cnt++;
            }
        }

        if (cnt == 7)
        {
            cout << "ascending\n";
            return 0;
        }
    }
    else if (input[0] == 8)
    {
        for (int i = 1; i < 8; ++i)
        {
            if (input[i] == 8 - i)
            {
                cnt++;
            }
        }

        if (cnt == 7)
        {
            cout << "descending\n";
            return 0;
        }
    }

    cout << "mixed\n";
}