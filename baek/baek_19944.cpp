#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    if (M == 1 || M == 2)
    {
        cout << "NEWBIE!\n";
    }
    else if (M <= N)
    {
        cout << "OLDBIE!\n";
    }
    else
    {
        cout << "TLE!\n";
    }
}