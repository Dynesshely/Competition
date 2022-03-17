#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, K = 130;
const int MAXN = 100010;
int n, q, rt, arr[MAXN];
long long a, b, x[N], l[N], r[N], dp[N];
#define M (L+R>>1)

struct seg{
    int ls, rs, l, r, sum, tag;
}segement[MAXN << 2];

inline int summid(int l, int r){ return (l + r) >> 1; }

inline void build(int x, int l, int r){
    seg * cur = &segement[x];
    (*cur).l = l, (*cur).r = r, (*cur).sum = 0, (*cur).tag = 0;
    if(l == r){ (*cur).sum = arr[l]; return; }
    int mid = summid(l, r);
    (*cur).ls = x << 1, (*cur).rs = (x << 1) | 1;
    build((*cur).ls, l, mid);
    build((*cur).rs, mid + 1, r);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

inline void pushup(int x, int v){
    seg * cur = &segement[x];
    (*cur).sum += v * ((*cur).r - (*cur).l + 1);
    (*cur).tag += v;
}

inline void pushdown(int x){
    seg * cur = &segement[x];
    pushup((*cur).ls, (*cur).tag);
    pushup((*cur).rs, (*cur).tag);
    (*cur).tag = 0;
}

// 线段树 -> 区间修改
inline void modify(int x, int l, int r, int v){
    seg * cur = &segement[x];
    pushdown(x); // 区间修改
    if((*cur).l == l && (*cur).r == r){ pushup(x, v); return; }
    int mid = summid((*cur).l, (*cur).r);
    if(l > mid) modify((*cur).rs, l, r, v);
    else if(r <= mid) modify((*cur).ls, l, r, v);
    else modify((*cur).ls, l, mid, v), modify((*cur).rs, mid + 1, r, v);
}

// 线段树 -> 单点修改
inline void modify(int x, int p, int v){
    seg * cur = &segement[x];
    if((*cur).l == (*cur).r){ (*cur).sum += v; return; }
    if(p <= summid((*cur).l, (*cur).r)) modify((*cur).ls, p, v);
    else modify((*cur).rs, p, v);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

inline int query(int x, int l, int r){
    seg * cur = &segement[x];
    pushdown(x); // 区间修改
    if((*cur).l == l && (*cur).r == r) return (*cur).sum;
    int mid = summid((*cur).l, (*cur).r);
    if(l > mid) return query((*cur).rs, l, r);
    else if(r <= mid) return query((*cur).ls, l, r);
    else return query((*cur).ls, l, mid) + query((*cur).rs, mid + 1, r);
}

struct segment_tree{
    int lz[N * K], ls[N * K], rs[N * K], t;
    inline void Update(long long l, long long r, int a,
        long long L, long long R, int&k){
            if(!k) k = ++t;
            if(l <= L && R <= r){ lz[k] = a; return; }
            if(l <= M) Update(l, r, a, L, M, ls[k]);
            if(r > M) Update(l, r, a, M + 1, R, rs[k]);
        }
    inline int Query(long long p, long long L, long long R, int k){
        if(!k) return n + 1;
        if(L == R) return lz[k] ? lz[K] : n + 1;
        return min(lz[k] ? lz[k] : n + 1, p <= M ? Query(p, L, M, ls[k]) : Query(p, M + 1, R, rs[k]));
    }
}t;

int main(){
    long long y;
    scanf("%d %lld %lld", &n, &a, &b);
    for(int i = 1; i <= n + 1; ++ i){
        scanf("%lld", x + i);
        x[i] = x[i - 1] + x[i];
        l[i] = (a - x[i] % (a + b) + (a + b)) % (a + b);
        r[i] = (a + b - 1 - x[i] % (a + b) + (a + b)) % (a + b);
    }
    dp[n + 1] = 0;
    for(int i = n; i; -- i){
        int j = t.Query((r[i] + 1) % (a + b), 0, a + b - 1, rt);
        dp[i] = j == n + 1 ? 0 : dp[j] + (r[j] - r[i] + (a + b)) % (a + b);
        if(l[i] <= r[i]) t.Update(l[i], r[i], i, 0, a + b - 1, rt);
        else{
            t.Update(l[i], a + b - 1, i, 0, a + b - 1, rt);
            t.Update(0, r[i], i, 0, a + b - 1, rt);
        }
    }
    for(scanf("%d", &q); q--; ){
        scanf("%lld", &y);
        int j = t.Query(y % (a + b), 0, a + b - 1, rt);
        printf("%lld\n", (j == n + 1 ? 0 : dp[j] + (r[j] - y % (a + b) + 1 + (a + b)) % (a + b)) + x[n + 1] + y);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int maxn = 5e4 + 5;
// int n, g, r, q, d[maxn], t[maxn];
// long long ans = 0, stdt = 0, f[maxn];
// int main(){
//     scanf("%d %d %d", &n, &g, &r);
//     for(int i = 1; i <= n + 1; i++){
//         scanf("%d", &d[i]);
//         stdt += d[i];
//         f[i] = f[i - 1] + d[i];
//     }
//     scanf("%d", &q);
//     for(int i = 1; i <= q; i++){
//         scanf("%d", &t[i]);
//         ans = stdt;

//     }
//     return 0;
// }

