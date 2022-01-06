#include <bits/stdc++.h>
using namespace std;

int N, input;
int total = 0;
int arr[21][21];
int curTeam = 0;
int ans = 987654321;
bool sTeam[21]; // 스타트 팀에 있는 사람은 True

int calStart()
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (sTeam[i])
        {
            for (int j = 1; j <= N; j++)
            {
                if (sTeam[j])
                {
                    sum += arr[i][j];
                }
            }
        }
    }
    return sum;
}
int calLink()
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!sTeam[i])
        {
            for (int j = 1; j <= N; j++)
            {
                if (!sTeam[j])
                {
                    sum += arr[i][j];
                }
            }
        }
    }
    return sum;
}

void makeTeam(int pre)
{
    if (curTeam == N / 2)
    {
        int StartTeam = calStart();
        int LinkTeam = calLink();
        int now = abs(StartTeam - LinkTeam);
        ans = min(ans, now);
    }
    else
    {
        for (int j = pre + 1; j <= N; j++)
        {
            curTeam += 1;
            sTeam[j] = true;
            makeTeam(j);
            sTeam[j] = false;
            curTeam -= 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    fill(&arr[0][0], &arr[20][21], 0);
    fill(&sTeam[0], &sTeam[20], false);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            total += arr[i][j];
        }
    }

    for (int i = 1; i <= N / 2 + 1; i++)
    {
        curTeam += 1;
        sTeam[i] = true;
        makeTeam(i);
        sTeam[i] = false;
        curTeam -= 1;
    }

    cout << ans << '\n';
}