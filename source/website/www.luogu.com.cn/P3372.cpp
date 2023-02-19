#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int n, os;
long long arr[MAXN];

struct seg{
    int ls, rs, l, r;
	long long sum, tag;
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

inline void pushup(int x, long long v){
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
inline void modify(int x, int l, int r, long long v){
    seg * cur = &segement[x];
    pushdown(x); // 区间修改
    if((*cur).l == l && (*cur).r == r){ pushup(x, v); return; }
    int mid = summid((*cur).l, (*cur).r);
    if(l > mid) modify((*cur).rs, l, r, v);
    else if(r <= mid) modify((*cur).ls, l, r, v);
    else modify((*cur).ls, l, mid, v), modify((*cur).rs, mid + 1, r, v);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

// 线段树 -> 单点修改
inline void modify(int x, int p, long long v){
    seg * cur = &segement[x];
    if((*cur).l == (*cur).r){ (*cur).sum += v; return; }
    if(p <= summid((*cur).l, (*cur).r)) modify((*cur).ls, p, v);
    else modify((*cur).rs, p, v);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

inline long long query(int x, int l, int r){
    seg * cur = &segement[x];
    pushdown(x); // 区间修改
    if((*cur).l == l && (*cur).r == r) return (*cur).sum;
    int mid = summid((*cur).l, (*cur).r);
    if(l > mid) return query((*cur).rs, l, r);
    else if(r <= mid) return query((*cur).ls, l, r);
    else return query((*cur).ls, l, mid) + query((*cur).rs, mid + 1, r);
}

int main(){
    scanf("%d %d", &n, &os);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &arr[i]);
    }
    build(1, 1, n);
    while(os--){
        int op; scanf("%d", &op);
        if(op == 2){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }else if(op == 1){
            int l, r;
            long long v;
            scanf("%d %d %lld", &l, &r, &v);
            modify(1, l, r, v);
        }
    }
    return 0;
}