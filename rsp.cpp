
#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    srand(time(NULL));
    int ran = rand() % 3;
    cout << "너를 승리로 이끌 손모양 >> ";

    if (ran == 0)
    {
        cout << "가위\n";
    }
    else if (ran == 1)
    {
        cout << "바위\n";
    }
    else
    {
        cout << "보\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    Solve();
    return 0;
}