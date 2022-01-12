#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int sum = brown + yellow;

    for (int col = 3; col <= 987654321; col++)
    {
        for (int row = 3; row <= col; row++)
        {
            if (col < row)
                break;

            if ((col - 2) * (row - 2) == yellow && row * col == sum)
            {

                answer.push_back(col);
                answer.push_back(row);
                col = 987654322;
                break;
            }
            else if (col * row > brown + yellow)
            {
                break;
            }
        }
    }

    return answer;
}