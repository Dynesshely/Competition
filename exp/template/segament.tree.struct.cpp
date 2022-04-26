// Copyright (c) Catrol 2022-present.
// ALL RIGHTS RESERVED.
// Author:   Dynesshely/Catrol
// E-Mail:   catrol@qq.com
// Date:     2022-04-26

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "misc-no-recursion"

#include <bits/stdc++.h>

const int maxn = 1e6 + 7;

typedef long long i64;

struct SegamentTree {
    private:
        struct Segament {
            i64 ls, rs, l, r, sum, mul, tag_sum, tag_mul = 1;
        } s[maxn << 2];

        static inline i64 Average(i64 a, i64 b) { return (a + b) >> 1; }

        inline void PushUP_Add(i64 x, i64 v) {
            s[x].sum += v * (s[x].r - s[x].l + 1);
            s[x].tag_sum += v;
        }

        inline void PushUP_Mul(i64 x, i64 v) {
            s[x].mul *= std::pow(v, s[x].r - s[x].l + 1);
            s[x].tag_mul *= v;
        }

        inline void PushDown(i64 x) {
            PushUP_Add(s[x].ls, s[x].tag_sum);
            PushUP_Add(s[x].rs, s[x].tag_sum);
            PushUP_Mul(s[x].ls, s[x].tag_mul);
            PushUP_Mul(s[x].rs, s[x].tag_mul);
            s[x].tag_sum = 0;
            s[x].tag_mul = 1;
        }

        inline void Update(i64 x){
            s[x].sum = s[s[x].ls].sum + s[s[x].rs].sum;
            s[x].mul = s[s[x].ls].mul * s[s[x].rs].mul;
        }

    public:
        i64 arr[maxn];

        inline void Build(i64 x, i64 l, i64 r) {
            s[x].l = l, s[x].r = r, s[x].sum = 0, s[x].tag_sum = 0;
            if (l == r) {
                s[x].sum = arr[l];
                s[x].mul = arr[l];
                return;
            }
            i64 mid = Average(l, r);
            s[x].ls = x << 1, s[x].rs = (x << 1) | 1;
            Build(s[x].ls, l, mid);
            Build(s[x].rs, mid + 1, r);
            Update(x);
        }

        inline void Modify(i64 x, i64 p, i64 v) {
            if (s[x].l == s[x].r) {
                s[x].sum += v;
                s[x].mul *= v;
                return;
            }
            if (p <= Average(s[x].l, s[x].r)) Modify(s[x].ls, p, v);
            else Modify(s[x].rs, p, v);
            Update(x);
        }

        inline void Modify(i64 x, i64 l, i64 r, i64 v) {
            PushDown(x);
            if (s[x].l == l && s[x].r == r) {
                PushUP_Add(x, v);
                PushUP_Mul(x, v);
                return;
            }
            i64 mid = Average(s[x].l, s[x].r);
            if (l > mid) Modify(s[x].rs, l, r, v);
            else if (r <= mid) Modify(s[x].ls, l, r, v);
            else Modify(s[x].ls, l, mid, v), Modify(s[x].rs, mid + 1, r, v);
            Update(x);
        }

        inline i64 Query_Sum(i64 x, i64 l, i64 r) {
            PushDown(x);
            if (s[x].l == l && s[x].r == r) return s[x].sum;
            i64 mid = Average(s[x].l, s[x].r);
            if (l > mid) return Query_Sum(s[x].rs, l, r);
            else if (r <= mid) return Query_Sum(s[x].ls, l, r);
            else return Query_Sum(s[x].ls, l, mid) + Query_Sum(s[x].rs, mid + 1, r);
        }

        inline i64 Query_Mul(i64 x, i64 l, i64 r) {
            PushDown(x);
            if (s[x].l == l && s[x].r == r) return s[x].mul;
            i64 mid = Average(s[x].l, s[x].r);
            if (l > mid) return Query_Mul(s[x].rs, l, r);
            else if (r <= mid) return Query_Mul(s[x].ls, l, r);
            else return Query_Mul(s[x].ls, l, mid) * Query_Mul(s[x].rs, mid + 1, r);
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
                printf("%lld\n", st.Query_Sum(1, x, y));
                break;
        }
    }
    return 0;
}

#pragma clang diagnostic pop