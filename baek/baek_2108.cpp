#include <bits/stdc++.h>
using namespace std;

const int MX = 8001;
int cnt[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int tmp, sum = 0;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;

        v.push_back(tmp);
        sum += tmp;
        cnt[tmp + 4000]++;
    }

    sort(v.begin(), v.end());

    // 산술평균 출력
    cout << round(double(sum) / N) << "\n";
    // 중앙값 출력
    if (N == 1)
        cout << v[0] << "\n";
    else
        cout << v[(N + 1) / 2 - 1] << "\n";

    // 최빈값 출력
    int flag;
    int max = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i]; // 최빈값 저장
            flag = i;     // 최빈값이 저장되어 있는 인덱스 저장
        }
    }

    // 최빈값이 여러개일 때 다음으로 작은거!
    for (int i = flag + 1; i < 8001; i++)
    {
        if (cnt[i] == max)
        {
            flag = i;
            break;
        }
    }

    cout << flag - 4000 << "\n";

    // 범위 출력
    cout << v[N - 1] - v[0] << "\n";
}