// DFS
#include <string>
#include <vector>

using namespace std;

int ans = 0;
int len;
int sum = 0;
vector<int> copy_vec;
void DFS(int idx, int target)
{
    if (idx == len)
    {
        if (target == sum)
            ans++;
        return;
    }

    sum += copy_vec.at(idx);
    DFS(idx + 1, target);
    sum -= (2 * copy_vec.at(idx));
    DFS(idx + 1, target);
    sum += copy_vec.at(idx);
    return;
}

int solution(vector<int> numbers, int target)
{
    len = numbers.size();
    copy_vec = numbers;
    sum += numbers.at(0);
    DFS(1, target);
    sum -= (2 * numbers.at(0));
    DFS(1, target);

    return ans;
}