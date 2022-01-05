#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int height = 0;

int solution(vector<vector<int>> triangle)
{

    for (int i = 1; i < triangle.size(); i++)
    {
        int len = triangle[i].size();

        for (int j = 0; j < len; j++)
        {
            if (j == 0)
            {
                triangle[i].at(j) += triangle[i - 1].at(0);
            }
            else if (j == len - 1)
            {
                triangle[i].at(j) += triangle[i - 1].at(j - 1);
            }
            else
            {
                int max_pre = max(triangle[i - 1].at(j - 1), triangle[i - 1].at(j));
                triangle[i].at(j) += max_pre;
            }
        }
    }

    height = triangle.size() - 1;
    for (int i = 0; i < triangle[height].size(); i++)
    {
        answer = max(answer, triangle[height].at(i));
    }

    return answer;
}