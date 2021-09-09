#include <bits/stdc++.h>
using namespace std;

int n;
const long long MX = 1000000005;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<long long> v;
    vector<long long> duplicate_v;
    vector<long long> input;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
        input.push_back(tmp);
    }

    sort(v.begin(), v.end());
    long long tmp = MX;
    for (int i = 0; i < v.size(); i++)
    {
        if (tmp == v.at(i))
        {
            continue;
        }
        else
        {
            duplicate_v.push_back(v.at(i));
            tmp = v.at(i);
        }
    }

    for (int i = 0; i < input.size(); i++)
    {
        vector<long long>::iterator iter = lower_bound(duplicate_v.begin(), duplicate_v.end(), input.at(i));
        cout << iter - duplicate_v.begin() << " ";
    }
    cout << "\n";
}