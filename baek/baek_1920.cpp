#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void Solution(int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (end - start >= 0)
    {
        mid = (start + end) / 2;

        if (v[mid] == key)
        {
            cout << "1\n";
            return;
        }
        else if (v[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "0\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        Solution(N, tmp);
    }
}