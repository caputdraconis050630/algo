#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    /*
        K : 수강신청 가능 인원
        L : 대기 목록의 길이
    */
    int K, L;
    unordered_map<string, int> M;
    vector<pair<int, string>> V;
    cin >> K >> L;

    for (int i = 0; i < L; i++)
    {
        string tmp;
        cin >> tmp;
        M[tmp] = i;
    }

    int s = M.size();
    for (auto c = M.begin(); c != M.end(); c++)
    {
        V.push_back(make_pair(c->second, c->first));
    }

    sort(V.begin(), V.end());

    if (K >= V.size())
    {
        for (int i = 0; i < V.size(); i++)
        {
            cout << V[i].second << "\n";
        }
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            cout << V[i].second << "\n";
        }
    }
}