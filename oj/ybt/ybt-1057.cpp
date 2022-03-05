#include <bits/stdc++.h>
using namespace std;
int a, b; char o;
int main(){
    scanf("%d %d %c", &a, &b, &o);
    switch(o){
        case '+': printf("%d\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%d\n", a * b); break;
        case '/':
            if(b == 0) printf("Divided by zero!\n");
            else printf("%d\n", a / b);
            break;
        default: printf("Invalid operator!\n"); break;
    }
    return 0;
}