#include <bits/stdc++.h>
using namespace std;
int N, num[110], ave[110];
int main(){
    int sum;
    while(~scanf("%d", &N)){
        if(!N) break;
        sum = 0;
        for(int i = 1; i <= N; i ++){
            scanf("%d", &num[i]);
            ave[i] = num[i] / 2;
            ave[i] ++;
        }
        sort(ave + 1, ave + 1 + N);
        for(int i = 1; i <= N / 2 + 1; i ++)
            sum += ave[i];
        printf("%d\n", sum);
    }
    return 0;
}