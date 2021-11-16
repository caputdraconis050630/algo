#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    int time[101];
    for (int i = 0; i < N; i++)
    {
        cin >> time[i];
    }

    while (Q--)
    {
        int input;
        cin >> input;
        int cur = -1;
        for (int i = 0; i < N; i++)
        {
            cur += time[i];

            if (input <= cur)
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}