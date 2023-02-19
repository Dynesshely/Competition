#include <bits/stdc++.h>
using namespace std;

/* It's not nice */
// const int maxn = 0x3fffff;
// const int maxm = 0x3fffff;
// int n, last = 0x7fffffff, tmp, maxmum = -0x7fffffff, ne[maxn], cnt[maxn], k = 0;

// int main(){
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++ i){
//         scanf("%d", &tmp);
//         ++ cnt[tmp];
//         last = min(last, tmp);
//         maxmum = max(maxmum, tmp);
//     }
//     for(int i = 1; i <= maxmum; ++ i)
//         if(cnt[i] > 0){
//             ne[last] = i, last = i;
//             printf(">>\tne[%d] = %d, %d = %d\n", last, i, last, i);
//         }
//     while(true){
//         for(int i = 0; i < cnt[last]; ++ i)
//             printf("%d ", last);
//         last = ne[last];
//         ++ k;
//         if(k == n) break;
//     }
//     return 0;
// }
