#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T, k;

deque<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    while(T--){
        cin>>k;
        v.clear();

        while(k--){
            char cmd;
            int tar;
            cin>>cmd>>tar;

            if(cmd == 'I'){
                v.push_back(tar);
            }
            else{
                // cmd == 'D'
                if(!v.empty()){
                    if(tar == 1){
                        // 최댓값 삭제
                        sort(v.begin(), v.end());
                        v.pop_back();
                    }
                    else{
                        // 최솟값 삭제
                        sort(v.begin(), v.end());
                        v.pop_front();
                    }
                }
            }

        }
        if(v.empty()){
            cout<<"EMPTY\n";
        }
        else{
            // v is not empty
            sort(v.begin(), v.end());
            cout<<v.back()<<" "<<v.front()<<"\n";
        }
    }
}