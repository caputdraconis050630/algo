#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000 * 2 + 1;
bool arr[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp + 1000000] = true;
    }

    for (int i = 0; i < MX; i++)
    {
        if (arr[i])
        {
            cout << i - 1000000 << "\n";
        }
    }
}