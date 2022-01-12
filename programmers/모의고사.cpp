#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> student_1 = {1, 2, 3, 4, 5};
vector<int> student_2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> student_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int ansCnt[3] = {0, 0, 0}; // 각 학생의 정답수를 저장할 배열

    int testCnt = answers.size();

    int cnt = 0;
    int stu_1_len = student_1.size();
    int stu_2_len = student_2.size();
    int stu_3_len = student_3.size();

    for (auto c : answers)
    {
        // #1
        if (c == student_1.at(cnt % stu_1_len))
        {
            ansCnt[0]++;
        }

        // #2
        if (c == student_2.at(cnt % stu_2_len))
        {
            ansCnt[1]++;
        }
        // #3
        if (c == student_3.at(cnt % stu_3_len))
        {
            ansCnt[2]++;
        }

        cnt++;
    }

    if (ansCnt[0] >= ansCnt[1] && ansCnt[0] >= ansCnt[2])
    {
        answer.push_back(1);

        if (ansCnt[0] == ansCnt[1])
        {
            answer.push_back(2);
        }
        if (ansCnt[0] == ansCnt[2])
        {
            answer.push_back(3);
        }
    }
    else if (ansCnt[1] >= ansCnt[0] && ansCnt[1] >= ansCnt[2])
    {
        answer.push_back(2);

        if (ansCnt[1] == ansCnt[0])
        {
            answer.push_back(1);
        }
        if (ansCnt[1] == ansCnt[2])
        {
            answer.push_back(3);
        }
    }
    else if (ansCnt[2] >= ansCnt[0] && ansCnt[2] >= ansCnt[1])
    {
        answer.push_back(3);

        if (ansCnt[2] == ansCnt[0])
        {
            answer.push_back(1);
        }
        if (ansCnt[2] == ansCnt[1])
        {
            answer.push_back(2);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}