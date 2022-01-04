#include <bits/stdc++.h>
using namespace std;

bool arr[32]; // 여분 존재
int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    answer = n;

    sort(lost.begin(), lost.end());

    fill(&arr[0], &arr[31], false);

    for (int i = 0; i < reserve.size(); i++)
    {
        arr[reserve.at(i)] = true;
    }

    for (int i = 0; i < lost.size(); i++)
    {
        if (arr[lost.at(i)])
        {
            // 중복댐
            // 여분의 체육복 없이 자기거만 존재

            arr[lost.at(i)] = false;
            lost.at(i) = -1;
        }
    }

    for (int i = 0; i < lost.size(); i++)
    {
        if (lost.at(i) == -1)
        {
            continue;
        }
        else
        {
            if (arr[lost.at(i) - 1])
            {
                arr[lost.at(i) - 1] = false;
                answer++;
            }
            else if (arr[lost.at(i) + 1])
            {
                arr[lost.at(i) + 1] = false;
                answer++;
            }
            else
            {
                answer--;
            }
        }
    }

    return answer;
}