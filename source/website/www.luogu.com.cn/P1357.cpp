#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long n;
int       m, k;

struct Mat {
    int                       sz;
    vector<vector<long long>> a;
    Mat(int s)
        : sz(s)
        , a(s, vector<long long>(s, 0)) {}
    Mat operator*(const Mat &o) const {
        Mat r(sz);
        for (int i = 0; i < sz; i++)
            for (int k = 0; k < sz; k++)
                if (a[i][k])
                    for (int j = 0; j < sz; j++)
                        if (o.a[k][j])
                            r.a[i][j] = (r.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return r;
    }
};

Mat qpow(Mat a, long long b) {
    Mat r(a.sz);
    for (int i = 0; i < a.sz; i++)
        r.a[i][i] = 1;
    while (b) {
        if (b & 1)
            r = r * a;
        a = a * a;
        b >>= 1;
    }
    return r;
}

void input() { scanf("%lld %d %d", &n, &m, &k); }

void process() {
    int         mask = (1 << m) - 1;
    vector<int> st;
    for (int s = 0; s <= mask; s++)
        if (__builtin_popcount(s) <= k)
            st.push_back(s);
    int sz = st.size();
    int id[32];
    memset(id, -1, sizeof(id));
    for (int i = 0; i < sz; i++)
        id[st[i]] = i;

    Mat A(sz);
    for (int i = 0; i < sz; i++) {
        int s = st[i];
        for (int b = 0; b <= 1; b++) {
            int ns = ((s << 1) & mask) | b;
            if (id[ns] != -1)
                A.a[i][id[ns]]++;
        }
    }

    Mat       An  = qpow(A, n);
    long long ans = 0;
    for (int i = 0; i < sz; i++)
        ans = (ans + An.a[i][i]) % MOD;
    printf("%lld\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
