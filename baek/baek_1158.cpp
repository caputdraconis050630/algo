#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    list<int> L;

    list<int>::iterator iter;
    int len = N; // initial length
    // init
    for (int i = 1; i <= N; i++)
    {
        L.push_back(i);
    }

    iter = L.begin();
    for (int i = 0; i < K - 1; i++)
        iter++;
    cout << "<";

    while (!L.empty())
    {
        cout << *iter;
        if (iter == L.end())
        {
            iter = L.begin();
            L.erase(L.end());
        }
        else
        {
            L.erase(iter);
        }

        if (!L.empty())
        {
            cout << ", ";
        }
        else
        {
            break;
        }
        for (int i = 0; i < K; i++)
        {
            if (*iter == L.back())
                iter = L.begin();
            else
                iter++;
        }
    }

    cout << ">";
}