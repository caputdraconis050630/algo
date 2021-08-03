#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, input, sum = 0;
    int pos = 0;
    int stack[100001];
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> input;
        if (input != 0)
        {
            stack[pos] = input;
            pos++;
        }
        else
        {
            pos--;
        }
    }

    for (int i = 0; i < pos; i++)
    {
        sum += stack[i];
    }
    cout << sum;
}