#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int k, T, tar;
    char cmd;
    multiset<int> ms;

    cin >> T;

    while (T--)
    {
        cin >> k;
        ms.clear();
        while (k--)
        {
            cin >> cmd >> tar;

            if (cmd == 'I')
            {
                ms.insert(tar);
            }
            else
            {
                // cmd == 'D'
                if (ms.empty())
                {
                    continue;
                }

                if (tar == 1)
                {
                    // 최댓값 삭제
                    ms.erase(prev(ms.end()));
                }
                else
                {
                    // 최솟값 삭제
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        }
    }
}