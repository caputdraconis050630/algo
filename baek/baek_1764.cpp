// Binary Search

#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<string> result;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        if (binary_search(v.begin(), v.end(), tmp))
        {
            result.push_back(tmp);
        }
    }

    sort(result.begin(), result.end());
    int size = result.size();
    cout << size << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\n";
    }
}