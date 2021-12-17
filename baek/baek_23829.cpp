#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, Q, S;
vector<int> V;

/*
    binary search
    return index
*/
int bs(int tar)
{
    int start = 0;
    int end = S - 1;
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (V.at(mid) == tar)
        {
            return mid;
        }
        else if (V.at(mid) > tar)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return mid + 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int input;

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    S = V.size();
    sort(V.begin(), V.end());

    for (int i = 0; i < Q; i++)
    {
        cin >> input;

        int idx = bs(input);

        int ans = 0;

        for (int j = 0; j <= idx; j++)
        {
            ans += (input - V.at(j));
        }
        for (int j = idx + 1; j < N; j++)
        {
            if (j >= N)
                break;
            ans += (V.at(j) - input);
        }

        cout << ans << "\n";
    }

    return 0;
}