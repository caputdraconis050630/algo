#include <bits/stdc++.h>
using namespace std;

int N; // 종이에 적은 수의 개수

vector<int> V;     // 종이에 적은 수를 저장할 벡터
vector<int> ans_V; // 정답을 저장할 벡터(최대공약수의 약수들을 저장하는 벡터)

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    return gcd(q, p % q);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int tmp;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        V.push_back(tmp);
    }

    sort(V.begin(), V.end()); // 오름차순으로 정렬

    // g는 입력된 모든 수의 공약수
    int g = gcd(V[1] - V[0], V[1] - V[0]);

    for (int i = 2; i < N; i++)
    {
        g = gcd(g, V[i] - V[i - 1]);
    }

    // 최대공약수의 약수들을 ans_V에 넣어주기
    for (int i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            if (i == 1)
            {
                ans_V.push_back(g);
            }
            else if (i * i == g)
            {
                ans_V.push_back(i);
            }
            else
            {
                ans_V.push_back(i);
                ans_V.push_back(g / i);
            }
        }
    }

    // 정답 벡터 정렬
    sort(ans_V.begin(), ans_V.end());

    // 정답 출력
    for (int i = 0; i < ans_V.size(); i++)
    {
        cout << ans_V[i] << ' ';
    }

    return 0; // 프로그램 정상종료
}