#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1073741824;
int main(){
    int *p;
    srand(time(0));
    p = (int *)calloc(MAXN, sizeof(int));
    if(p) printf("Memory Allocated at: %x\n",p);  
    else printf("Not Enough Memory!\n"); 
    memset(p, 1, MAXN);
    for(long long i = 0; i < MAXN; i += 1024){
        p[i] = rand() % 100;
        printf(">>\t%d: %d\n", p[i], i);
    }
    printf("Boom!\n");
    int q = 0;
    scanf("%d", &q);
    free(p);
    printf("Clean!\n");
    scanf("%d", &q);
    return 0;
}
