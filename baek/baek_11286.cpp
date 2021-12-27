#include <bits/stdc++.h>
using namespace std;

int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    priority_queue<int, vector<int>, less<int> > lessThanZero;
    priority_queue<int, vector<int>, greater<int> > greaterThanZero;

    while (N--)
    {
        int x;
        cin >> x;

        if (x != 0)
        {
            // add data
            if (x > 0)
            {
                greaterThanZero.push(x);
            }
            else
            {
                lessThanZero.push(x);
            }
        }
        else
        {
            // print data
            if (greaterThanZero.empty() && lessThanZero.empty())
            {
                cout << "0\n";
            }
            else if (greaterThanZero.empty())
            {
                // lessThanZero에만 데이터 존재
                int data = lessThanZero.top();
                lessThanZero.pop();

                cout << data << "\n";
            }
            else if (lessThanZero.empty())
            {
                // greaterThanZero에만 데이터 존재
                int data = greaterThanZero.top();
                greaterThanZero.pop();

                cout << data << "\n";
            }
            else
            {
                int greater = greaterThanZero.top();
                int less = abs(lessThanZero.top());
                int data;
                if (greater > less)
                {
                    data = lessThanZero.top();
                    lessThanZero.pop();
                }
                else if (greater < less)
                {
                    data = greaterThanZero.top();
                    greaterThanZero.pop();
                }
                else
                {
                    // 절댓값이 같은 경우
                    data = lessThanZero.top();
                    lessThanZero.pop();
                }
                cout << data << "\n";
            }
        }
    }
    return 0;
}