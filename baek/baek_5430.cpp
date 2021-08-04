#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int tc; // test case
    cin >> tc;
    string op, arr;
    int n;
    deque<int> d;

    bool front_back = true; // 배열이 뒤집어진 상태인지 아닌지를 나타내는 변수 , true가 기본값
    bool print_result = true;

    while (tc--)
    {
        print_result = true;
        front_back = true;
        d.clear();
        cin >> op;
        cin >> n;

        // 양 옆 대괄호 필터링
        cin >> arr;
        int len = arr.length();
        arr = arr.substr(1, len - 2);
        // cout << arr;
        // 구분자 쉼표 제거
        if (n == 0)
        {
            cout << "error\n";
            break;
        }
        int current = arr.find(',');
        int start = 0;

        while (current != -1)
        {
            d.push_back(stoi(arr.substr(start, current - start)));
            start = current + 1;
            current = arr.find(',', start);
        }
        d.push_back(stoi(arr.substr(start, current - start)));

        for (auto c : op)
        {
            //cout << c << "\n";
            if (c == 'R')
            {
                front_back = !front_back;
            }
            else
            { // 첫번째 숫자를 지우는 D operation
                if (d.empty())
                {
                    cout << "error\n";
                    print_result = false;
                    break;
                }
                if (front_back)
                {
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }

        // 결과 출력
        // 뒤집어진 상태면 뒤부터 출력
        if (print_result)
        {
            if (d.empty())
            {
                cout << "[]\n";
                break;
            }
            else
            {
                cout << "[";
                if (front_back)
                {
                    for (int i = 0; i < d.size() - 1; ++i)
                    {
                        cout << d[i] << ",";
                    }
                    cout << d.back() << "]\n";
                }
                else
                {

                    for (int i = d.size() - 1; i > 0; --i)
                    {
                        cout << d[i] << ",";
                    }
                    cout << d.front() << "]\n";
                }
            }
        }
    }
}