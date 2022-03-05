#include <bits/stdc++.h>
using namespace std;
int x, y;
int main(){
    scanf("%d %d", &x, &y);
    if(x >= -1 && x <= 1 && y >= -1 && y <= 1) printf("yes\n");
    else printf("no\n");
    return 0;
}