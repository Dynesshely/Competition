#include <bits/stdc++.h>
using namespace std;

int    n, k, m;
int    pa[301], ma[301];
double phi[301][301];
bool   vis[301][301];
int    qx[90001], qy[90001];

double calc(int i, int j) {
    if (vis[i][j])
        return phi[i][j];
    vis[i][j] = vis[j][i] = true;
    if (i == j) {
        if (pa[i])
            phi[i][i] = 0.5 * (1.0 + calc(pa[i], ma[i]));
        else
            phi[i][i] = 0.5;
    } else if (pa[i]) {
        phi[i][j] = 0.5 * (calc(pa[i], j) + calc(ma[i], j));
    } else if (pa[j]) {
        phi[i][j] = 0.5 * (calc(i, pa[j]) + calc(i, ma[j]));
    } else {
        phi[i][j] = 0.0;
    }
    phi[j][i] = phi[i][j];
    return phi[i][j];
}

void printPct(double v) {
    double p = 200.0 * v;
    if (fabs(p) < 1e-12) {
        printf("0%%\n");
        return;
    }
    long long ip = (long long)(p + 0.5);
    if (fabs(p - ip) < 1e-9) {
        printf("%lld%%\n", ip);
        return;
    }
    char s[64];
    sprintf(s, "%.15f", p);
    int   len = strlen(s);
    char *dot = strchr(s, '.');
    if (dot) {
        while (len > 1 && s[len - 1] == '0')
            len--;
        if (s[len - 1] == '.')
            len--;
    }
    s[len] = '\0';
    printf("%s%%\n", s);
}

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        pa[a] = b;
        ma[a] = c;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &qx[i], &qy[i]);
}

void process() {
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            calc(i, j);
}

void output() {
    for (int i = 0; i < m; i++)
        printPct(phi[qx[i]][qy[i]]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
