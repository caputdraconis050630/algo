#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    int N, M;
    cin >> tc;

    bool flag = false;

        while (tc--)
    {
        // 초기화

        int cnt = 0; // 몇번째로 인쇄?
        /*
        N : 문서의 개수(1 <= N <= 100)
        M : 궁금한 문서가 몇번째 놓여 있는지 ( 첫번재는 0 )
        */
        cin >> N >> M;
        deque<pair<int, int>> important;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            important.push_back(make_pair(0, tmp));
        }
        important[M].first = 1;

        int chk = 0;
        // 방금 출력한 문서의 first 값이 1이 아닌 동안 반복

        while (chk != 1)
        {
            chk = 0;
            flag = false;
            int tmp = important[0].second;

            // 뒤에 중요도가 더 높은 문서가 존재?
            for (int i = 1; i < important.size(); i++)
            {
                if (tmp < important[i].second)
                {
                    flag = true; // 존재한다!
                    break;
                }
            }

            if (flag)
            {
                pair<int, int> q;
                q = important.front();
                important.push_back(q);
                important.pop_front();
            }
            else
            {
                // 조건에 성립해서 출력
                chk = important[0].first;
                important.pop_front();
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}