#include <iostream>
using namespace std;


int main(void){
    int input_cnt;

    int tmp;
    cin>>tmp; // 첫번째 입력 받기
    int max = tmp;
    input_cnt=1;

    while(input_cnt<=9){
        
        cin>>tmp;

        if(max < tmp){
            max = tmp;
        }
        input_cnt++;
    }

    cout<<max<<"\n";
    return 0;
}