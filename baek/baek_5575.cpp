#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int time[3][6];
    for(int i=0;i<3;i++){
        cin>>time[i][0]>>time[i][1]>>time[i][2]>>time[i][3]>>time[i][4]>>time[i][5];
    }

    for(int i=0;i<3;i++){
        int h, m, s;
        h = time[i][3] - time[i][0];
        m = time[i][4] - time[i][1];
        s = time[i][5] - time[i][2];

        if(s<0){
            m--;
            s+=60;
        }

        if(m<0){
            if(m==-60) h-2;
            else{
                h--;
            }

            m+=60;
            
        }

        cout<<h<<" "<<m<<" "<<s<<"\n";
    }
}