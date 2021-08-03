#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
    dat[tail] = x;
    tail++;
}

int empty()
{
    if (head == tail)
        return 1;
    else
        return 0;
}

void pop()
{
    if (head == tail)
        cout << "-1\n";
    else
        cout << dat[head++] << "\n";
}

int size()
{
    return tail - head;
}

int front()
{
    if (empty())
        return -1;
    else
        return dat[head];
}

int back()
{
    if (empty())
        return -1;
    else
        return dat[tail - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, tmp;
    string op;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> tmp;
            push(tmp);
        }
        else if (op == "pop")
        {
            pop();
        }
        else if (op == "size")
        {
            cout << size() << "\n";
        }
        else if (op == "empty")
        {
            cout << empty() << "\n";
        }
        else if (op == "front")
        {
            cout << front() << "\n";
        }
        else
        {
            cout << back() << "\n";
        }
    }
}