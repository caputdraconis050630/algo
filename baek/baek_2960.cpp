#include <bits/stdc++.h>
using namespace std;

bool arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int cnt = 0;
    cin >> N >> K;

    // 기존의 에라토스테네스의 체는 소수를 true로 바꾸지만, 이 문제는 아님
    // arr[2] = true;
    // arr[3] = true;

    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (!arr[j])
            {
                arr[j] = true;
                if (++cnt == K)
                {
                    cout << j << "\n";
                    break;
                }
            }
        }
    }
}