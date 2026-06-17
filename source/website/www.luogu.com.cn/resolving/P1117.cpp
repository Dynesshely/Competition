#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 60005;

int lg[MAXN];

struct SuffixArray {
    int ws[MAXN], wa[MAXN], wb[MAXN];
    int sa[MAXN], rk[MAXN], height[MAXN];
    int best[MAXN][20];

    bool doCmp(int *r, int a, int b, int l) { return r[a] == r[b] && r[a + l] == r[b + l]; }

    void build(char *s, int n, int m) {
        int *x = wa, *y = wb;
        for (int i = 1; i <= n; ++i)
            ++ws[x[i] = s[i] - 'a' + 1];
        for (int i = 2; i <= m; ++i)
            ws[i] += ws[i - 1];
        for (int i = n; i >= 1; --i)
            sa[ws[x[i]]--] = i;
        fill(ws + 1, ws + 1 + m, 0);
        for (int j = 1, p = 0; p < n; j <<= 1, m = p) {
            p = 0;
            for (int i = n - j + 1; i <= n; ++i)
                y[++p] = i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > j)
                    y[++p] = sa[i] - j;
            for (int i = 1; i <= n; ++i)
                ++ws[x[i]];
            for (int i = 2; i <= m; ++i)
                ws[i] += ws[i - 1];
            for (int i = n; i >= 1; --i)
                sa[ws[x[y[i]]]--] = y[i];
            fill(ws + 1, ws + 1 + m, 0);
            swap(x, y);
            p = 0;
            for (int i = 1; i <= n; ++i)
                x[sa[i]] = doCmp(y, sa[i], sa[i - 1], j) ? p : ++p;
        }
        for (int i = 1; i <= n; ++i)
            rk[sa[i]] = i;
        for (int i = 1, j = 0; i <= n; ++i) {
            if (j)
                --j;
            while (s[i + j] == s[sa[rk[i] - 1] + j])
                ++j;
            height[rk[i]] = j;
        }
    }

    void doInit(int n) {
        for (int i = 1; i <= n; ++i)
            best[i][0] = height[i];
        for (int j = 1; j <= lg[n]; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                best[i][j] = min(best[i][j - 1], best[i + (1 << (j - 1))][j - 1]);
    }

    int doQuery(int x, int y) {
        x = rk[x], y = rk[y];
        if (x > y)
            swap(x, y);
        ++x;
        int k = lg[y - x + 1];
        return min(best[x][k], best[y - (1 << k) + 1][k]);
    }

    void doClear() {
        memset(wa, 0, sizeof(wa));
        memset(wb, 0, sizeof(wb));
    }
} sa, rsa;

char s[MAXN];
int  n, pre[MAXN], suf[MAXN];

void input() { scanf("%s", s + 1); }

void process() {
    n = strlen(s + 1);
    sa.build(s, n, 26);
    sa.doInit(n);
    reverse(s + 1, s + 1 + n);
    rsa.build(s, n, 26);
    rsa.doInit(n);
    reverse(s + 1, s + 1 + n);
    for (int len = 1; len <= n; ++len)
        for (int i = 1; i + len <= n; i += len) {
            int lcp = sa.doQuery(i, i + len), lcs = rsa.doQuery(n + 1 - i, n + 1 - i - len);
            if (lcp + lcs - 1 >= len) {
                ++pre[i + len + max(len - lcs, 0)];
                --pre[i + len + min(lcp, len)];
                ++suf[i - max(len - lcp, 0)];
                --suf[i - min(lcs, len)];
            }
        }
    for (int i = 1; i <= n; ++i)
        pre[i] += pre[i - 1];
    for (int i = n; i >= 1; --i)
        suf[i] += suf[i + 1];
    ll ans = 0;
    for (int i = 1; i < n; ++i)
        ans += (ll)pre[i] * suf[i + 1];
    printf("%lld\n", ans);
}

void output() {}

int main() {
    lg[0] = -1;
    for (int i = 1; i < MAXN; ++i)
        lg[i] = lg[i >> 1] + 1;
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        process();
        output();
        sa.doClear(), rsa.doClear();
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));
    }
    return 0;
}
