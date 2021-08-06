// bruete force

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int cnt = 0;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        if (v[i] == 1)
        {
            cnt++;
        }
        else
        {
            for (int j = 2; j < v[i]; j++)
            {
                if (v[i] % j == 0)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << N - cnt << "\n";
}