#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int king, queen, look, bishop, knight, pon;
    cin >> king >> queen >> look >> bishop >> knight >> pon;

    cout << 1 - king << " " << 1 - queen << " " << 2 - look << " " << 2 - bishop << " " << 2 - knight << " " << 8 - pon << "\n";
}