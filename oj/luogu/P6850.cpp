#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g, h, i;
int main(){
    scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
    if(50 + a + b + c + d + e + f + g + (h == 1 ? 5 : 0) >= i)
        printf("AKIOI\n");
    else printf("AFO\n");
    return 0;
}