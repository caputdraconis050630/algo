// With STL Stack

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int N, X;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }
        else if (op == "pop")
        {
            if (st.empty())
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (op == "size")
        {
            cout << st.size() << "\n";
        }
        else if (op == "empty")
        {
            cout << st.empty() << "\n";
        }
        else
        {
            // op == "top"
            if (st.empty())
            {
                cout << "-1"
                     << "\n";
            }
            else
                cout << st.top() << "\n";
        }
    }
}