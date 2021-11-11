#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
        map<string, int> clothes;

        for (int i = 0; i < n; i++)
        {
            string tmp, type;
            cin >> tmp >> type;

            clothes[type]++;
        }
        int ans = 1;
        for (auto i = clothes.begin(); i != clothes.end(); i++)
        {
            ans *= i->second + 1;
        }

        cout << ans - 1 << "\n";
    }
}