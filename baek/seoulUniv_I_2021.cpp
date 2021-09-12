#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;

    string input;
    cin>>input;

    bool front_back=true;

    for(int i=0;i<input.size();i++){
        if(input[i] == '-'){
            front_back = !front_back;
        }
        else{
            if(front_back){
                d.push_back(input[i]-'0');
            }
            else{
                d.push_front(input[i]-'0');
            }
        }

        
    }


}

