#include <bits/stdc++.h>

using namespace std;

int zero_cnt = 0;    // 0의 개수
int present_cnt = 0; // 0을 제외하고 맞춘 개수
bool arr[46];

int prize[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    fill(&arr[0], &arr[45], false);

    for (int i = 0; i < 6; i++)
    {
        arr[win_nums.at(i)] = true;
    }

    for (int i = 0; i < 6; i++)
    {
        if (lottos.at(i) == 0)
        {
            zero_cnt++;
        }
        else
        {
            if (arr[lottos.at(i)])
                present_cnt++;
        }
    }

    // highest
    answer.push_back(prize[present_cnt + zero_cnt]);

    // lowest
    answer.push_back(prize[present_cnt]);

    return answer;
}