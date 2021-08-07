#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int H, W, N;
        cin >> H >> W >> N;

        int num = (N - 1) / H + 1;

        if (N % H == 0)
        {
            // 맨 꼭대기 층이 할당 될 때
            num += 100 * H;
        }
        else
        {
            num += (N % H) * 100;
        }

        cout << num << "\n";
    }
}