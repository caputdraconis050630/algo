#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N == 0)
    {
        cout << "0\n";
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int remove_data_num = round(N * 0.15);

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = remove_data_num; i < N - remove_data_num; i++)
    {
        sum += v.at(i);
    }

    cout << round(double(sum) / (N - 2 * remove_data_num)) << "\n";
}