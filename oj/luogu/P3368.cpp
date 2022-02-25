/*
    树状数组模板题 2
*/

#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;

const int n = 500005;
int N, M, a[n], c[n], t[n];

int query(int x){
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i)) ret += t[i];
    return ret;
}

void edit(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)) c[i] += v;
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++ i) scanf("%d", &a[i]), edit(i, a[i]);
    for(int i = 1; i <= M; ++ i){
        int op; scanf("%d", &op);
        if(op == 1){
            int x, v; scanf("%d%d", &x, &v);
            edit(x, v);
        }else{
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", query(y) - query(x - 1));
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define lowbit(x) (x & (-x))
// using namespace std;
// const int maxn = 100001;

// int t[maxn], a[maxn], n, m, c = 0, ans[maxn];

// void add(int x, int d){
//     while(x <= maxn){ t[x] += d; x += lowbit(x); }
// }

// int sum(int l, int r){
//     int suml_1 = 0, sumr = 0;
//     l = l - 1;
//     while(l > 0){ suml_1 += t[l]; l -= lowbit(l); }
//     while(r > 0){ sumr += t[r]; r -= lowbit(r); }
//     return sumr - suml_1;
// }

// int main(){
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; ++ i){ scanf("%d", &a[i]); add(i, a[i]); }
//     while(m--){
//         int op; scanf("%d", &op);
//         if(op == 1){
//             int x, d;
//             scanf("%d%d", &x, &d);
//             add(x, d);
//         }else{
//             int l, r;
//             scanf("%d%d", &l, &r);
//             ans[c++] = sum(l, r);
//         }
//     }
//     for(int i = 0; i < n; ++ i) printf("%d\n", ans[i]);
//     return 0;
// }

