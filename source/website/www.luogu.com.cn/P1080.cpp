#include <bits/stdc++.h>
using namespace std;

struct Min { int a, b; } m[1005];

struct Big {
    int d[1005], len;
    Big() { memset(d, 0, sizeof(d)); len = 1; }
    Big(int x) { memset(d, 0, sizeof(d)); len = 0; while (x) { d[len++] = x % 10000; x /= 10000; } if (len == 0) len = 1; }
    void mul(int x) {
        int c = 0;
        for (int i = 0; i < len; ++i) { c += d[i] * x; d[i] = c % 10000; c /= 10000; }
        while (c) { d[len++] = c % 10000; c /= 10000; }
    }
    Big div(int x) const {
        Big r; r.len = len; int rem = 0;
        for (int i = len - 1; i >= 0; --i) { rem = rem * 10000 + d[i]; r.d[i] = rem / x; rem %= x; }
        while (r.len > 1 && r.d[r.len - 1] == 0) --r.len;
        return r;
    }
    bool operator<(const Big &b) const {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; --i) if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
    void print() { printf("%d", d[len - 1]); for (int i = len - 2; i >= 0; --i) printf("%04d", d[i]); printf("\n"); }
};

int main() {
    int n, ka, kb;
    scanf("%d%d%d", &n, &ka, &kb);
    for (int i = 0; i < n; ++i) scanf("%d%d", &m[i].a, &m[i].b);
    sort(m, m + n, [](const Min &x, const Min &y) { return x.a * x.b < y.a * y.b; });
    Big prod(ka), ans(0);
    for (int i = 0; i < n; ++i) {
        Big cur = prod.div(m[i].b);
        if (ans < cur) ans = cur;
        prod.mul(m[i].a);
    }
    ans.print();
    return 0;
}
