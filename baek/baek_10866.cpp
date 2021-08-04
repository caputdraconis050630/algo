#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    deque<int> deq;

    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;
        if (op == "push_front")
        {
            int tmp;
            cin >> tmp;
            deq.push_front(tmp);
        }
        else if (op == "push_back")
        {
            int tmp;
            cin >> tmp;
            deq.push_back(tmp);
        }
        else if (op == "pop_front")
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }
        else if (op == "pop_back")
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }
        else if (op == "size")
        {
            cout << deq.size() << "\n";
        }
        else if (op == "empty")
        {
            cout << deq.empty() << "\n";
        }
        else if (op == "front")
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.front() << "\n";
            }
        }
        else
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.back() << "\n";
            }
        }
    }
}