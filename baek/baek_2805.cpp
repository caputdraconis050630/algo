#include <bits/stdc++.h>
using namespace std;

long long sum(vector<int> &v, int M)
{
    long long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) >= M)
        {
            sum += v.at(i) - M;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int max = 0;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int start = 0, end = 1000000001;
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (sum(v, middle) >= M)
        {
            if (max <= middle)
            {
                max = middle;
                start = middle + 1;
            }
        }
        else
        {
            end = middle - 1;
        }
    }

    cout << max << "\n";
}