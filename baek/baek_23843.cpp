// Greedy Algorithm

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N, M;
ll arr[11];
deque<ll> V;

bool cmp(ll &a, ll &b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    fill(&arr[0], &arr[10], 0);

    cin >> N >> M;

    ll input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        V.push_back(input);
    }

    // 내림차순으로 정렬
    sort(V.begin(), V.end(), cmp);

    ll time = 0;

    while (!V.empty())
    {
        for (int i = 0; i < M; i++)
        {
            if (arr[i] <= time)
            {
                arr[i] += V.front();
                V.pop_front();
            }
        }
        time++;
    }
    ll ans = 0;
    for (int i = 0; i < M; i++)
    {
        ans = max(arr[i], ans);
    }
    cout << ans << "\n";
}