#include <bits/stdc++.h>
using namespace std;

const int MAX = 600001;
int pre[MAX], nxt[MAX];
char dat[MAX];

int unused = 1;
void insert(int addr, char num)
{
    dat[unused] = num;       // 새로운 원소를 생성
    pre[unused] = addr;      // 새 원소의 pre 값에 삽입할 위치의 주소를 대입
    nxt[unused] = nxt[addr]; // 새 원소의 nxt 값에 삽입할 위치의 nxt값을 대입
    nxt[addr] = unused;      // 삽입할 위치의 nxt값을 새 원소로 변경
    if (nxt[addr] != -1)
        pre[nxt[unused]] = unused; // 삽입할 위치의 다음 원소의 pre값을 새 원소로 변경
    unused++;
}

void erase(int addr)
{
    int nxt_addr = nxt[addr];
    int pre_addr = pre[addr];

    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
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
    cursor = init.length();
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        if (op == 'P')
        {
            char add;
            cin >> add;
            insert(cursor, add);
        }
        else if (op == 'L')
        {
            if (pre[cursor] != 0)
                cursor = pre[cursor];
        }
        else if (op == 'D')
        {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        }
        else
        {
            // op == 'B'
        }
    }
}