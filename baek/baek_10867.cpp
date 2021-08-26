#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int tmp;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    tmp = 1200; // 임의의 값
    for (int i = 0; i < N; i++)
    {
        if (tmp != v.at(i))
        {
            cout << v.at(i) << " ";
        }
        tmp = v.at(i);
    }
}