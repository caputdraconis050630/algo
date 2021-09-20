#include <bits/stdc++.h>
using namespace std;

int T; // Test Case
int k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    
    

    while(T--){
        cin>>k;
        multiset<int> ms;

        for(int i=0;i<k;i++){
            char cmd;
            int target;
            cin>>cmd>>target;

            if(cmd == 'I'){
                ms.insert(target);
            }
            else{
                // cmd == 'D'
                if(!ms.empty() && target == -1){
                    ms.erase(ms.begin());
                }
                else if(!ms.empty() && target == 1){
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }

        if(ms.empty()){
            cout<<"EMPTY\n";
        }
        else{
            auto end_iter = ms.end();
            end_iter--;
            cout<<*end_iter<<' '<<*ms.begin()<<'\n';
        }
    }

}