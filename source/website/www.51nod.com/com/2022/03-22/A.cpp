#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
char gc() {
    static char buf[1 << 16], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, 1 << 16, stdin);
        if (s == t)
            return EOF;
    }
    return *s++;
}
// #define getchar gc
ll read() {
    char c;
    ll w = 1;
    while ((c = getchar()) > '9' || c < '0')
        if (c == '-')
            w = -1;
    ll ans = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        ans = (ans << 1) + (ans << 3) + c - '0';
    return ans * w;
}
void pc(char c, int op) {
    static char buf[1 << 16], *s = buf, *t = buf + (1 << 16);
    (op || ((*s++ = c) && s == t)) && (fwrite(buf, 1, s - buf, stdout), s = buf);
}
void wt(int x) {
    if (x > 9)
        wt(x / 10);
    pc('0' + x % 10, 0);
}
void wts(int x, char op) {
    if (x < 0)
        pc('-', 0), x = -x;
    wt(x);
    pc(op, 0);
}
int mod = 1e9 + 7;
int n, k;
const int xx = 1e6 + 5;
ll jiec[xx], ni[xx];
ll ksm(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans *= a, ans %= mod;
        a *= a, a %= mod, b >>= 1;
    }
    return ans;
}
ll C(ll n, ll m) { return (n < m || n < 0 || m < 0) ? 0 : jiec[n] * ni[m] % mod * ni[n - m] % mod; }
ll g(int n, int m) { return n == 0 && m == 1 ? 1 : (C(n + m - 2, n - 1) - C(n + m - 2, n - 2) + mod) % mod; }
signed main() {
    n = read(), k = read(), mod = read();
    jiec[0] = 1;
    for (int i = 1; i < xx; i++)
        jiec[i] = jiec[i - 1] * i % mod;
    ni[xx - 1] = ksm(jiec[xx - 1], mod - 2);
    for (int i = xx - 2; i >= 0; i--)
        ni[i] = ni[i + 1] * (i + 1) % mod;
    ll sum = 0;
    for (int i = 2; i <= n - (k - 1) + 1; i++)
        sum += g(k - 1, n + 2 - i), sum %= mod;
    cout << sum * ksm(2, max(0ll, n - k - 1)) % mod << "\n";
    pc('1', 1);
    return 0;
}
