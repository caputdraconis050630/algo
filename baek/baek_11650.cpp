#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    vector<pair<int, int> > v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}