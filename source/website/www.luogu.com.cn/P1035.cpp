#include <bits/stdc++.h>
using namespace std;
int calculate(int k){
    double sn=0,index=1;
    while(1){
        sn+=1/index;
        index++;
        if(sn>k){
            return index-1;
        }
    } 
}

int main()
{
    int K;
    cin>>K;
    cout<<calculate(K);
    return 0;
}