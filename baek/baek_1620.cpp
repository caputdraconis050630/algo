#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    int N, M;
    int tmp;

    cin >> N >> M;
    vector<string> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    vector<pair<string, int>> sorted_v(N); // 포켓몬 이름과 번호를 같이 넣으며 이름으로 정렬할 벡터 선언

    for (int i = 0; i < N; i++)
    {
        sorted_v[i].first = v[i + 1];
        sorted_v[i].second = i + 1;
    }

    sort(sorted_v.begin(), sorted_v.end()); // 이분탐색을 위한 정렬

    for (int i = 0; i < M; i++)
    {
        cin >> input; // 검색어 입력
        if (input[0] >= 65 && input[0] <= 90)
        {
            // 포켓몬 이름으로 검색어가 들어왔을 때
            int low = 0, high = N - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (sorted_v[mid].first == input)
                {
                    // 중간값과 일치할 때
                    cout << sorted_v[mid].second << "\n";
                    break;
                }
                else if (sorted_v[mid].first < input)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        else
        {
            // 포켓몬 번호로 검색어가 들어왔을 때
            tmp = stoi(input);
            cout << v[tmp] << "\n";
        }
    }
}