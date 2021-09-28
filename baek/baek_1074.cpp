#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c) // 찾는 위치 도달
    {
        cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 현재 사분면을 또 다시 4분할
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size; // 없으면 그 사이즈만큼 더하기
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;
    Z(0, 0, (1 << n)); // 1<<n은 2^n 값
    return 0;
}