#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int       n, m;
int       a[MAXN];
long long bit1[MAXN], bit2[MAXN];

void add(long long bit[], int pos, long long val) {
    while (pos <= n) {
        bit[pos] += val;
        pos += pos & -pos;
    }
}

long long sum(long long bit[], int pos) {
    long long res = 0;
    while (pos > 0) {
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;
}

void rangeAdd(int l, int r, long long val, long long bit[]) {
    add(bit, l, val);
    add(bit, r + 1, -val);
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    while (m--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int l, r, K, D;
            scanf("%d%d%d%d", &l, &r, &K, &D);
            long long A = K - 1LL * l * D;
            long long B = D;
            rangeAdd(l, r, A, bit1);
            rangeAdd(l, r, B, bit2);
        } else {
            int p;
            scanf("%d", &p);
            long long ans = a[p] + sum(bit1, p) + p * sum(bit2, p);
            printf("%lld\n", ans);
        }
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
