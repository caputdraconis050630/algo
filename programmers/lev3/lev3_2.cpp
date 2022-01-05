#include <bits/stdc++.h>

using namespace std;

vector<int> V; // 한 줄의 정수열이 들어갈 벡터
vector<vector<int>> copy_triangle;
int current = 0; // 현재 V에 들어가있는 높이
int answer = 0;
int height = 0;
int max_ans = 0;

void add(int idx)
{
    if (current + 1 == height)
    {
        max_ans = max(answer, max_ans);
        return;
    }

    current += 1;

    answer += copy_triangle[current][idx];
    add(idx);
    answer -= copy_triangle[current][idx];

    answer += copy_triangle[current][idx + 1];
    add(idx + 1);
    answer -= copy_triangle[current][idx + 1];

    current -= 1;
}

int solution(vector<vector<int>> triangle)
{

    height = triangle.size();

    copy_triangle = triangle;

    answer += triangle[0][0];
    add(0);

    return max_ans;
}