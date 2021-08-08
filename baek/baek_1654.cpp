#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 랜선의 개수 K, 필요한 랜선의 개수 N 입력
    int K, N;
    cin >> K >> N;

    // 기존 랜선의 길이 저장할 배열 선언
    int lan_cable[K];

    int sum = 0;
    // 가지고 있는 K개의 랜선 길이 입력
    for (int i = 0; i < K; i++)
    {
        cin >> lan_cable[i];
        sum += lan_cable[i];
    }

    int max = sum / N;

    // 노가다 시작
    while (max--)
    {
        int cnt = 0;
        for (int i = 0; i < K; i++)
        {
            cnt += lan_cable[i] / max;
        }
        if (cnt >= N)
        {
            cout << max << "\n";
            return 0;
        }
    }
}