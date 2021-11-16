#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V;

void sol(int sp, int cnt)
{
    if (M == cnt)
    {
        for (int k = 0; k < M; k++)
        {
            cout << V.at(k) << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = sp; i <= N; i++)
    {
        V.push_back(i);
        sol(i + 1, cnt + 1);
        V.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    sol(1, 0);

    return 0;
}