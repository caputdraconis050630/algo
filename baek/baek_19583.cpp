#include <bits/stdc++.h>
using namespace std;

string S, E, Q;

/*
    ~ S(동시에도 해당) : 입장 확인
    E ~ Q : 퇴장 확인
*/

bool isBefore(int s_hour, int s_minute, int e_hour, int e_minute)
{
    if (s_hour < e_hour)
    {
        return true;
    }
    if (s_hour == e_hour && s_minute <= e_minute)
    {
        return true;
    }

    return false;
}

bool isAfter(int s_hour, int s_minute, int e_hour, int e_minute)
{
    if (s_hour > e_hour)
    {
        return true;
    }
    if (s_hour == e_hour && s_minute >= e_minute)
    {
        return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> S >> E >> Q;

    int ans = 0;

    int s_hour = stoi(S.substr(0, 2));
    int s_minute = stoi(S.substr(3, 2));

    int e_hour = stoi(E.substr(0, 2));
    int e_minute = stoi(E.substr(3, 2));

    int q_hour = stoi(Q.substr(0, 2));
    int q_minute = stoi(Q.substr(3, 2));

    map<string, int> M;

    string time, user_name;
    int log_hour, log_minute;

    while (!cin.eof())
    {
        cin >> time >> user_name;

        log_hour = stoi(time.substr(0, 2));
        log_minute = stoi(time.substr(3, 2));

        if (isBefore(log_hour, log_minute, s_hour, s_minute))
        {
            // 개강총회 시작 전 입장
            M[user_name] = 1;
        }
        else if (isAfter(log_hour, log_minute, e_hour, e_minute) && isBefore(log_hour, log_minute, q_hour, q_minute))
        {
            // 퇴장 확인
            if (M[user_name] == 1)
            {
                // 입장 확인된 유저인지 확인
                M[user_name] = 2; // 중복 체크를 방지하기 위해 2로 변경
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}