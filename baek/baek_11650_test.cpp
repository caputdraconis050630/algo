#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(2, 0));
    v.push_back(make_pair(2, 2));

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 4; ++i)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}