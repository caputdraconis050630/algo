// With Array Stack

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st[10001];
    int pos = 0;

    int N, X;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int tmp;
            cin >> tmp;
            st[pos] = tmp;
            pos++;
        }
        else if (op == "pop")
        {
            if (pos == 0)
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << st[pos - 1] << "\n";
                pos--;
            }
        }
        else if (op == "size")
        {
            cout << pos << "\n";
        }
        else if (op == "empty")
        {
            if (pos == 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            // op == "top"
            if (pos == 0)
            {
                cout << "-1"
                     << "\n";
            }
            else
                cout << st[pos - 1] << "\n";
        }
    }
}