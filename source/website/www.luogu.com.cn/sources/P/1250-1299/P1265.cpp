#include <bits/stdc++.h>
using namespace std;

int    n;
int    x[5005], y[5005];
double dist[5005];
bool   via[5005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
}

void process() {
    for (int i = 1; i <= n; i++)
        dist[i] = 1e30;
    dist[1]    = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        int    u       = -1;
        double minDist = 1e30;
        for (int j = 1; j <= n; j++)
            if (!via[j] && dist[j] < minDist) {
                minDist = dist[j];
                u       = j;
            }
        via[u] = true;
        ans += sqrt(minDist);
        for (int j = 1; j <= n; j++)
            if (!via[j]) {
                double dx = x[u] - x[j];
                double dy = y[u] - y[j];
                double d  = dx * dx + dy * dy;
                if (d < dist[j])
                    dist[j] = d;
            }
    }
    printf("%.2f\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
