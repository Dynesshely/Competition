#include <bits/stdc++.h>
using namespace std;

int    n, m;
double prob[1001][1001];
double pow2[1001];

void input() { scanf("%d%d", &n, &m); }

void process() {
    pow2[0] = 1.0;
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i - 1] * 0.5;
    prob[1][1] = 1.0;
    for (int cur = 2; cur <= n; cur++) {
        double *g = prob[cur - 1];
        double *f = prob[cur];
        double  sum2[1001];
        sum2[1] = 0.0;
        for (int k = 2; k <= cur; k++)
            sum2[k] = g[k - 1] + 0.5 * sum2[k - 1];
        f[1] = (1.0 / 6.0) * (1.0 + sum2[cur]) / (1.0 - pow2[cur]);
        for (int k = 2; k <= cur; k++)
            f[k] = pow2[k - 1] * f[1] + (1.0 / 3.0) * sum2[k];
    }
}

void output() { printf("%.9lf\n", prob[n][m]); }

int main() {
    input();
    process();
    output();
    return 0;
}
