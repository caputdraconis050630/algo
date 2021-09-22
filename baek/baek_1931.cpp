#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start; // 회의 시작 시간
    int end;   // 회의 끝 시간
};

vector<meeting> V;

bool comp(const meeting &fir, const meeting &sec)
{
    // sort 함수에 쓰일 비교 함수
    if (fir.end == sec.end)
    {
        // 끝나는 시간이 같을 시 시작이 빠른 순으로 정렬
        return fir.start < sec.start;
    }
    // 종료 시간이 빠른 순으로 정렬
    return fir.end < sec.end;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        meeting tmp;
        int s, e;
        cin >> s >> e;
        tmp.start = s;
        tmp.end = e;
        V.push_back(tmp);
    }

    sort(V.begin(), V.end(), comp);

    int last = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (V[i].start >= last)
        {
            last = V[i].end;
            cnt++;
        }
    }

    cout << cnt << "\n";
}