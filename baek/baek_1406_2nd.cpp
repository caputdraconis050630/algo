#include <bits/stdc++.h>
using namespace std;

const int MAX = 600001;
int pre[MAX], nxt[MAX];
char dat[MAX];

int unused = 1;
void insert(char data)
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cursor;

    string init; // 초기 문자열 입력
    cin >> init;
    char op;
    int q;

    // 초기 문자열 대입
    for (auto c : init)
    {
        insert(cursor, c);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        if (op == 'P')
        {
        }
        else if (op == 'L')
        {
            if (cursor != nxt[0])
                cursor = nxt[0];
        }
        else if (op == 'D')
        {
        }
        else
        {
            // op == 'B'
        }
    }
}