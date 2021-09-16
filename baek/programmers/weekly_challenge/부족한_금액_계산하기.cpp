#include <bits/stdc++.h>

using namespace std;

long long solution(int price, int money, int count)
{
    // price : 이용료, money : 가지고 있던 금액 count : 타고 있는 횟수
    long long long_money = money;
    for(int i=1;i<=count;i++){
        long_money -= i * price;
    }
    if(long_money <=0){
        return -1 * long_money;
    }
    else{
        return 0;
    }
}
