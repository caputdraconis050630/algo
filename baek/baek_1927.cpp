#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
    int n;
    for (scanf("%d", &n); n--;)
    {
        ll i;
        scanf("%lld", &i);
        if (!i)
        {
            if (q.empty())
                printf("0\n");
            else
            {
                printf("%lld\n", q.top());
                q.pop();
            }
        }
        else
            q.push(i);
    }
    return 0;
}