#include <bits/stdc++.h>
using namespace std;

int t, n, r;
double pr[10005][1000];
int main(){
    scanf("%d", &t);
    for(int i = 0; i <= 10000; ++ i) pr[i] = sqrt(i);
    for(int i = 0; i < t; ++ i){
        scanf("%d%d", &n, &r);
        long long sum = 0;
        for(int d = 1; d <= n; ++ d){
            if(((long long)(d * pr[r])) % 2 == 0) ++ sum;
            else -- sum;
        }
        printf("%lld\n", sum);
    }
    return 0;
}

// int t, n, r;
// int pa[100000010];
// bool via[1010000010];
// int main(){
//     scanf("%d", &t);
//     for(int i = 0; i < t; ++ i){
//         scanf("%d%d", &n, &r);
//         long long sum = 0;
//         for(int d = 1; d <= n; ++ d){
//             int index = (r - 1) * n + d;
//             if(index < 100000000) if(via[index]) sum += pa[index];
//             else{
//                 if(index < 100000000){
//                     pa[index] = pow(-1, (int)(d * sqrt(r)));
//                     sum += pa[index];
//                     via[index] = true;
//                 }else{
//                     sum += pow(-1, (int)(d * sqrt(r)));
//                 }
//             }
//         }
//         printf("%lld\n", sum);
//     }
//     return 0;
// }