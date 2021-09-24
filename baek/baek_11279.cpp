#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue<ll, vector<ll>, less<ll> > pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int input;
    cin >> N;

    while (N--)
    {
        cin >> input;
        if (input != 0)
        {
            pq.push(input);
        }
        else
        {
            // input == 0
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
            {
                cout << "0\n";
            }
        }
    }
    return 0;
}