#include <bits/stdc++.h>

#define Price first
#define Weight second
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    pair<int, int> jew[300005]; // 가격 무게
    multiset<int> bag;

    for (int i = 0; i < N; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.Weight >> tmp.Price;

        jew[i] = tmp;
    }

    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;

        bag.insert(tmp);
    }

    sort(jew, jew + N); // 가격을 기준으로 오름차순으로 정렬

    long long ans = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        pair<int, int> cur = jew[i];

        auto it = bag.lower_bound(cur.Weight);

        if (it == bag.end())
            continue;
        ans += cur.Price;

        bag.erase(it);
    }

    cout << ans << "\n";
}