#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 700005;
const int E = 2000005;

struct A {
    int nx, x, w;
} e1[E];

struct B {
    int nx, n, m, k;
    ll  w;
} e2[E];

int n, m, k, mx;

int c1, c2;

int hd1[E], hd2[E];

int mu[N], pre[N];
int pr[N], vis[N];

int fac[2005];

ll ans;

void input();
void process();
void output();

int S(int);
ll  F(int, int, int);

int main() {
    input();
    process();
    output();
    return 0;
}

void input() { scanf("%d%d%d", &n, &m, &k); }

void process() {

    mx = min(N - 5, max(k, min(n, m)));

    mu[1]  = 1;
    pre[1] = 1;

    for (int i = 2; i <= mx; i++) {

        if (!vis[i]) {
            pr[++pr[0]] = i;
            mu[i]       = -1;
        }

        for (int j = 1; j <= pr[0] && 1LL * i * pr[j] <= mx; j++) {

            int x = i * pr[j];

            vis[x] = 1;

            if (i % pr[j]) {
                mu[x] = -mu[i];
            } else {
                mu[x] = 0;
                break;
            }
        }

        pre[i] = pre[i - 1] + mu[i];
    }

    for (int i = 1; i <= k; i++)
        if (k % i == 0)
            fac[++fac[0]] = i;

    ans = F(n, m, k);
}

void output() { printf("%lld\n", ans); }

int S(int x) {

    if (x <= mx)
        return pre[x];

    int p = (x + 2017) % E;

    for (int i = hd1[p]; i; i = e1[i].nx)
        if (e1[i].x == x)
            return e1[i].w;

    ++c1;

    e1[c1].nx = hd1[p];
    e1[c1].x  = x;
    e1[c1].w  = 1;

    hd1[p] = c1;

    int &ret = e1[c1].w;

    int i = 2;
    int j = sqrt(x);

    for (; i <= j; i++)
        ret -= S(x / i);

    for (; i <= x; i = j + 1) {
        j = x / (x / i);
        ret -= (j - i + 1) * S(x / i);
    }

    return ret;
}

ll F(int n, int m, int k) {

    if (!n || !m)
        return 0;

    int p = (2017LL * n + m + k) % E;

    for (int i = hd2[p]; i; i = e2[i].nx)
        if (e2[i].n == n && e2[i].m == m && e2[i].k == k)
            return e2[i].w;

    ++c2;

    e2[c2].nx = hd2[p];
    e2[c2].n  = n;
    e2[c2].m  = m;
    e2[c2].k  = k;
    e2[c2].w  = 0;

    hd2[p] = c2;

    ll &ret = e2[c2].w;

    if (k == 1) {

        if (n > m)
            swap(n, m);

        int i   = 1, j;
        int lst = 0, cur;
        int x, y;

        j = sqrt(n);

        for (; i <= j; i++) {

            cur = S(i);

            ret += 1LL * (n / i) * (m / i) * (cur - lst);

            lst = cur;
        }

        for (; i <= n; i = j + 1) {

            x = n / i;
            y = m / i;

            j = min(n / x, m / y);

            cur = S(j);

            ret += 1LL * x * y * (cur - lst);

            lst = cur;
        }

        p = (2017LL * m + n + 1) % E;

        ++c2;

        e2[c2].nx = hd2[p];
        e2[c2].n  = m;
        e2[c2].m  = n;
        e2[c2].k  = 1;
        e2[c2].w  = ret;

        hd2[p] = c2;
    } else {

        for (int i = 1; i <= fac[0] && fac[i] <= k; i++) {

            int d = fac[i];

            if (k % d == 0 && mu[d])
                ret += F(m / d, n, d) * mu[d];
        }
    }

    return ret;
}