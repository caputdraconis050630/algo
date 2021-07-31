#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt;
    cin >> N;
    if(N==0){
        cout<<"1";
        return 0;
    }
    while (N > 0)
    {
        freq[N % 10]++;
        N /= 10;
    }
    int max = freq[0];

    for (int i = 1; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        if (freq[i] > max)
            max = freq[i];
    }
    if (freq[6] + freq[9] > 2 * max)
    {
        cout << int(ceil(double(freq[6] + freq[9]) / 2));
    }
    else
    {
        cout << max;
    }
}