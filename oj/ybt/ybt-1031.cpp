#include<iostream>
using namespace std;
int main(){
    int a,ge,shi,bai;
    cin>>a;
    ge=a%10;
    shi=a/10%10;
    bai=a/100;
    cout<<ge<<shi<<bai;
    return 0;
 }
