#include <bits/stdc++.h>

using namespace std;

/*
        quiz type 1 : using map
         - key : member's name
         - value : team name
        
        quiz type 0 : using map & vector
    */

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> mp;
    map<string, int> team_num; // 팀 번호를 저장할 맵
    vector<string> team[100];

    for (int i = 0; i < N; i++)
    {
        int size;
        string team_name, member_name;
        cin >> team_name >> size;

        while (size--)
        {
            cin >> member_name;
            mp[member_name] = team_name;
            team_num[team_name] = i;
            team[i].push_back(member_name);
        }
    }

    while (M--)
    {
        int type;
        string name;
        cin >> name >> type;

        if (type == 0)
        {
            // 팀 멤버 출력
            int team_id = team_num[name];
            sort(team[team_id].begin(), team[team_id].end());
            for (auto c : team[team_id])
            {
                cout << c << "\n";
            }
        }
        else
        {
            // 팀 이름 출력
            cout << mp[name] << "\n";
        }
    }
}