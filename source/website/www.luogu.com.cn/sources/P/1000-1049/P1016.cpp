#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
double S, C, L, P0, D[10], P[10];
int N;
int main() {
    scanf("%lf%lf%lf%lf%d", &S, &C, &L, &P0, &N);
    for (int i = 1; i <= N; ++i)
        scanf("%lf%lf", &D[i], &P[i]);
    D[0] = 0; P[0] = P0;
    D[N + 1] = S; P[N + 1] = 0;
    N = N + 1;
    double maxd = C * L, cost = 0, gas = 0;
    int cur = 0;
    while (cur < N) {
        int nxt = -1, cheap = -1;
        double cheap_p = 1e18;
        for (int i = cur + 1; i <= N; ++i) {
            if (D[i] - D[cur] > maxd + EPS) break;
            if (P[i] < cheap_p - EPS) { cheap_p = P[i]; cheap = i; }
            if (nxt == -1 && P[i] < P[cur] - EPS) nxt = i;
        }
        if (cheap == -1) { printf("No Solution\n"); return 0; }
        if (nxt != -1) {
            double need = (D[nxt] - D[cur]) / L;
            double fill = need - gas;
            if (fill > EPS) { cost += fill * P[cur]; gas += fill; }
            gas -= need;
            cur = nxt;
        } else if (D[N] - D[cur] <= maxd + EPS) {
            double need = (D[N] - D[cur]) / L;
            double fill = need - gas;
            if (fill > EPS) cost += fill * P[cur];
            cur = N;
        } else {
            double fill = C - gas;
            cost += fill * P[cur];
            gas = C;
            double use = (D[cheap] - D[cur]) / L;
            gas -= use;
            cur = cheap;
        }
    }
    printf("%.2f\n", cost + EPS);
    return 0;
}
