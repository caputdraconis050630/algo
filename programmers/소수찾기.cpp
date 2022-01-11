#include <bits/stdc++.h>
using namespace std;

string tar = "";
int cntNum[10], cnt = 0, answer = 0;
map<int, bool> M; // 카운트 된 소수를 저장하는 맵

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void deeper(int cnt, int totalLength)
{
    if (cnt == totalLength)
    {
        int now = stoi(tar, nullptr);
        if (M.find(now) == M.end() && isPrime(now) == true)
        {
            M.insert({now, true});
            answer++;
        }
        return;
    }

    for (int z = 0; z <= 9; z++)
    {
        if (cntNum[z] > 0)
        {
            cnt++;
            tar.push_back((char)(z + 48));
            cntNum[z]--;
            deeper(cnt, totalLength);
            tar.pop_back();
            cntNum[z]++;
            cnt--;
        }
    }
}

int solution(string numbers)
{
    fill(cntNum, cntNum + 10, 0);

    for (auto c : numbers)
    {
        cntNum[c - '0']++;
    }

    for (int length = 1; length <= numbers.length(); length++)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (cntNum[i] > 0)
            {
                cnt++;
                tar.push_back((char)(i + 48));
                cntNum[i]--;
                deeper(cnt, length);
                tar.pop_back();
                cntNum[i]++;
                cnt--;
            }
        }
    }

    return answer;
}

int main(void)
{
    cout << solution("011");
}