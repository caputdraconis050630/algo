#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;

int arr[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int tmp;

    while (N--)
    {
        cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 1; i < MX; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << "\n";
        }
    }
}