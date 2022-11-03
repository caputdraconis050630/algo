#include "bits/stdc++.h"
using namespace std;

int arr[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
    cin >> s;
 
    int num = 0;
    int ans = 0;
    int flag = 1;
 
    for (char c : s) {
        if (c == '+') {
            //+가 나온 경우 숫자가 끝난 것이므로 num을 ans에 더해준 후 에 num을 0으로 초기화
            ans += num;
            num = 0;
        }
        else if (c == '-') {
            //- 인 경우 flag를 -1로 바꿔주고 이전까지의 num을 ans에 더해준다.
            //flag는 이후로 계속 -1 을 유지한다.
            flag = -1;
            ans += num;
 
            //더해줬으므로 num은 다시 0으로 초기화
            num = 0;
        }
        else {
            //숫자인 경우 num에 저장
            num = num * 10 + (c - '0')*flag;
        }
    }
 
    //마지막 숫자를 더해준다.
    ans += num;
 
    cout << ans << '\n';
 
    return 0;
}