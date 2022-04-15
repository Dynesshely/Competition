#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "misc-no-recursion"

// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

const int maxn = 1e6 + 7;

typedef long long i64;

struct SegamentTree {
    private:
        struct Segament {
            i64 ls, rs, l, r, sum, tag;
        } s[maxn << 2];

        static inline i64 Average(i64 a, i64 b) { return (a + b) >> 1; }

        inline void PushUP(i64 x, long long v) {
            s[x].sum += v * (s[x].r - s[x].l + 1);
            s[x].tag += v;
        }

        inline void PushDown(i64 x) {
            PushUP(s[x].ls, s[x].tag);
            PushUP(s[x].rs, s[x].tag);
            s[x].tag = 0;
        }

    public:
        i64 arr[maxn];

        inline void Build(i64 x, i64 l, i64 r) {
            s[x].l = l, s[x].r = r, s[x].sum = 0, s[x].tag = 0;
            if (l == r) {
                s[x].sum = arr[l];
                return;
            }
            i64 mid = Average(l, r);
            s[x].ls = x << 1, s[x].rs = (x << 1) | 1;
            Build(s[x].ls, l, mid);
            Build(s[x].rs, mid + 1, r);
            s[x].sum = s[s[x].ls].sum + s[s[x].rs].sum;
        }

        inline void Modify(i64 x, i64 p, i64 v) {
            if (s[x].l == s[x].r) {
                s[x].sum += v;
                return;
            }
            if (p <= Average(s[x].l, s[x].r)) Modify(s[x].ls, p, v);
            else Modify(s[x].rs, p, v);
            s[x].sum = s[s[x].ls].sum + s[s[x].rs].sum;
        }

        inline void Modify(i64 x, i64 l, i64 r, i64 v) {
            PushDown(x);
            if (s[x].l == l && s[x].r == r) {
                PushUP(x, v);
                return;
            }
            i64 mid = Average(s[x].l, s[x].r);
            if (l > mid) Modify(s[x].rs, l, r, v);
            else if (r <= mid) Modify(s[x].ls, l, r, v);
            else Modify(s[x].ls, l, mid, v), Modify(s[x].rs, mid + 1, r, v);
            s[x].sum = s[s[x].ls].sum + s[s[x].rs].sum;
        }

        inline i64 Query(i64 x, i64 l, i64 r) {
            PushDown(x);
            if (s[x].l == l && s[x].r == r) return s[x].sum;
            i64 mid = Average(s[x].l, s[x].r);
            if (l > mid) return Query(s[x].rs, l, r);
            else if (r <= mid) return Query(s[x].ls, l, r);
            else return Query(s[x].ls, l, mid) + Query(s[x].rs, mid + 1, r);
        }
} st;

int main() {
    int n, m, o;
    i64 x, y, k;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &st.arr[i]);
    st.Build(1, 1, n);

    for (int i = 1; i <= m; ++ i) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%lld %lld %lld", &x, &y, &k);
                st.Modify(1, x, y, k);
                break;
            case 2:
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", st.Query(1, x, y));
                break;
        }
    }
    return 0;
}

#pragma clang diagnostic pop