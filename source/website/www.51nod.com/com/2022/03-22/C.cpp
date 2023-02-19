#include <cstdio>
#include <cstdlib>
const int sz = 40400;
const int ljz = 1000000007;
int Tm(int x, int y) {
    long long a = x, b = y;
    return (a * b) % ljz;
}
void MOD(int &x) {
    if (x >= ljz)
        x -= ljz;
    if (x < 0)
        x += ljz;
}
int fpm(int x, int y) {
    int p = 1, s = x;
    for (; y; y >>= 1) {
        if (y & 1)
            p = Tm(p, s);
        s = Tm(s, s);
    }
    return p;
}
const int R = 1200000;
int fac[R + 42], ifac[R + 42];
int K;
int X[sz], Y[sz], F[sz];
int x, y, ax, ay, bx, by;
int C(int n, int k) {
    if (n < k)
        return 0;
    return Tm(fac[n], Tm(ifac[k], ifac[n - k]));
}
void prepare() {
    int i;
    for (i = fac[0] = 1; i <= R; i++)
        fac[i] = Tm(fac[i - 1], i);
    ifac[R] = fpm(fac[R], ljz - 2);
    for (i = R; i; i--)
        ifac[i - 1] = Tm(ifac[i], i);
}
bool turn(int dx, int dy, int &a, int &b) {
    int Bz = dy * ax - dx * ay, Bm = by * ax - bx * ay;
    if (Bz % Bm == 0 && (Bz / Bm) >= 0)
        b = Bz / Bm;
    else
        return 0;
    int Az = dx - b * bx, Am = ax;
    if (!ax) {
        Az = dy - b * by;
        Am = ay;
    }
    if (Az % Am == 0 && (Az / Am) >= 0)
        a = Az / Am;
    else
        return 0;
    return 1;
}
void init() {
    int i, j;
    scanf("%d %d %d", &x, &y, &K);
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    for (i = 1; i <= K; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        for (j = 1; j < i; j++)
            if (X[i] == X[j] && Y[i] == Y[j])
                break;
        if (j < i)
            K--, i--;
    }
}
int dp(int a) {
    int i, c, d;
    if (F[a])
        return F[a];
    if (turn(X[a], Y[a], c, d)) {
        F[a] = C(c + d, c);
        for (i = 1; i <= K; i++)
            if (X[a] != X[i] || Y[a] != Y[i])
                if (turn(X[a] - X[i], Y[a] - Y[i], c, d))
                    MOD(F[a] -= Tm(C(c + d, c), dp(i)));
    }
    return F[a];
}
void doit1() {
    int i;
    K++;
    X[K] = x;
    Y[K] = y;
    for (i = 1; i <= K; i++)
        F[i] = 0;
    printf("%d\n", dp(K));
}
int node[sz], next[sz], to[sz], e;
int NAL[sz], use[sz];
int S, T, A, B, shift = 1002;
void ins(int x, int y) {
    e++;
    next[e] = node[x];
    node[x] = e;
    to[e] = y;
}
int _node[sz], _next[sz], _to[sz], _;
void _ins(int x, int y) {
    _++;
    _next[_] = _node[x];
    _node[x] = _;
    _to[_] = y;
}
int q[sz], inq[sz];
void bfs(int s) {
    int i, j, k, l, r;
    for (i = 1; i < shift * 2; i++)
        inq[i] = 0, use[i] = 1;
    inq[q[l = r = 0] = s] = 1;
    while (l <= r) {
        k = q[l++];
        for (j = node[k]; j; j = next[j])
            if (!inq[to[j]])
                inq[q[++r] = to[j]] = 1;
    }
    for (i = 1; i < shift * 2; i++)
        if (!inq[i])
            use[i] = 0;
}
void rbfs(int s) {
    int i, j, k, l, r;
    for (i = 1; i < shift * 2; i++)
        inq[i] = 0;
    inq[q[l = r = 0] = s] = 1;
    while (l <= r) {
        k = q[l++];
        for (j = _node[k]; j; j = _next[j])
            if (!inq[_to[j]])
                inq[q[++r] = _to[j]] = 1;
    }
    for (i = 1; i < shift * 2; i++)
        if (!inq[i])
            use[i] = 0;
}
int deg[sz], QL;
int topsort() {
    int i, j, k, l, r;
    for (i = 1; i < shift * 2; i++)
        deg[i] = 0;
    for (i = 1; i < shift * 2; i++)
        if (use[i])
            for (j = node[i]; j; j = next[j])
                if (use[to[j]])
                    deg[to[j]]++;
    l = 1;
    r = 0;
    for (i = 1; i < shift * 2; i++)
        if (deg[i] == 0 && use[i])
            q[++r] = i;
    while (l <= r) {
        k = q[l++];
        for (j = node[k]; j; j = next[j])
            if (use[to[j]]) {
                deg[to[j]]--;
                if (deg[to[j]] == 0)
                    q[++r] = to[j];
            }
    }
    for (i = 1; i < shift * 2; i++)
        if (deg[i] > 0 && use[i])
            return 0;
    QL = r;
    return 1;
}
int f[sz];
int dp2(int t) {
    int i, j, k;
    for (i = 1; i < shift * 2; i++)
        f[i] = 0;
    f[shift] = 1;
    for (i = 1; i <= QL; i++) {
        k = q[i];
        for (j = node[k]; j; j = next[j])
            if (use[to[j]])
                MOD(f[to[j]] += f[k]);
    }
    return f[t];
}
void doit2() {
    int i;
    if (ax == 0 && ay == 0) {
        ax = bx;
        ay = by;
        bx = by = 0;
    }
    if (ax == 0 && ay == 0 && bx == 0 && by == 0) {
        if (x == 0 && y == 0)
            printf("-1\n");
        else
            printf("0\n");
        return;
    }
    if (ax * y != ay * x) {
        printf("0\n");
        return;
    }
    for (i = 1; i <= e; i++)
        next[i] = to[i] = _next[i] = _to[i] = 0;
    for (i = -1001; i <= 1001; i++)
        node[shift + i] = _node[shift + i] = 0;
    e = _ = 0;
    for (i = -1001; i <= 1001; i++)
        NAL[shift + i] = 0;
    if (ax != 0 || bx != 0) {
        T = x;
        for (i = 1; i <= K; i++)
            if (ax * Y[i] == ay * X[i])
                NAL[X[i] + shift] = 1;
        A = ax;
        B = bx;
    } else {
        T = y;
        for (i = 1; i <= K; i++)
            if (ax * Y[i] == ay * X[i])
                NAL[Y[i] + shift] = 1;
        A = ay;
        B = by;
    }
    S = shift;
    T += shift;
    for (i = -1001; i <= 1001; i++)
        if (!NAL[i + shift]) {
            if (i + A <= 1001 && i + A >= -1001 && !NAL[i + A + shift])
                ins(i + shift, i + A + shift), _ins(i + A + shift, i + shift);
            if (A != B)
                if (i + B <= 1001 && i + B >= -1001 && !NAL[i + B + shift])
                    ins(i + shift, i + B + shift), _ins(i + B + shift, i + shift);
        }
    ins(shift - 1001, shift - 1001);
    _ins(shift - 1001, shift - 1001);
    ins(shift + 1001, shift + 1001);
    _ins(shift + 1001, shift + 1001);
    bfs(S);
    rbfs(T);
    if (topsort())
        printf("%d\n", dp2(T));
    else
        printf("-1\n");
}
int main() {
    int t;
    prepare();
    scanf("%d", &t);
    while (t--) {
        init();
        if (ax * by != ay * bx)
            doit1();
        else
            doit2();
    }
    return 0;
}