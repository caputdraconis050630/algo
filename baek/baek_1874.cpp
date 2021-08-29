// Unsolve
#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;
int num[MX];
vector<char> ret;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int pos = 0;
    for (int i = 1; i <= N; i++)
    {
        // 기본적으로 하는 행동
        st.push(i);
        ret.push_back('+');

        while (!st.empty() && st.top() == num[pos])
        {
            pos++;
            ret.push_back('-');
            st.pop();
        }
    }

    if (!st.empty())
        cout << "NO\n";
    else
    {
        for (int i = 0; i < ret.size(); i++)
            cout << ret[i] << "\n";
    }

    return 0;
}