#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;
int num[MX];
vector<char> ret;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int pos = 0;
    for (int i = 1; i <= N; i++)
    {
        // 기본적으로 하는 행동
        // 바로 top에 있는 수와 일치하다고 해도 + - 로 pop 댐
        st.push(i);
        ret.push_back('+');

        // pop 부분
        while (!st.empty() && st.top() == num[pos])
        {
            pos++;
            ret.push_back('-');
            st.pop();
        }
    }

    /*
    결과 출력 부분
    */
    if (!st.empty())
        // 스택에 숫자가 남아있을 때 => 불가능한 수열이 주어짐
        // NO 출력
        cout << "NO\n";
    else
    {
        //
        for (int i = 0; i < ret.size(); i++)
            cout << ret[i] << "\n";
    }

    // 정상적으로 프로그램 종료
    return 0;
}