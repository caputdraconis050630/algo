#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> m;
    int index;
    string temp = "";
    for (index = 0; index < 26; index++)
    {
        temp += 'A' + index;
        m.emplace(temp, index + 1);
        temp = "";
    }

    for (int i = 0; i < msg.size(); i++)
    {
        temp = "";
        temp += msg[i];

        int k = i;
        int cnt = 0;

        while (m.find(temp) != m.end())
        {
            cnt += 1;
            k++;
            temp += msg[k];
        }

        i += cnt - 1;
        m.emplace(temp, ++index);
        temp.pop_back();           // 뒤에 한 글자 제거
        answer.push_back(m[temp]); // 사전에 존재하는 문자열의 색인 번호 답 벡터에 추가
    }

    return answer;
}
