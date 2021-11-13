#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-";
    if (t->tm_mon + 1 < 10)
    {
        cout << "0" << t->tm_mon + 1;
    }
    else
    {
        cout << t->tm_mon + 1;
    }
    cout << "-";
    cout << t->tm_mday << "\n";
}