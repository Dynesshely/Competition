#include <bits/stdc++.h>
using namespace std;

double       dist, capacity, efficiency, initCost;
int          n;
double       d[55], p[55], dp[55];
const double INF = 1e18;
const double EPS = 1e-9;

void input() {
    scanf("%lf", &dist);
    scanf("%lf %lf %lf %d", &capacity, &efficiency, &initCost, &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &d[i], &p[i]);
}

void process() {
    d[0]           = 0;
    double half    = capacity / 2.0;
    double maxDist = capacity * efficiency;
    for (int i = n; i >= 0; i--) {
        dp[i] = INF;
        for (int j = i + 1; j <= n + 1; j++) {
            double target = j == n + 1 ? dist : d[j];
            double dis    = target - d[i];
            if (dis > maxDist + EPS)
                break;
            bool valid = true;
            for (int k = i + 1; k < j && valid; k++) {
                double fuelAtK = capacity - (d[k] - d[i]) / efficiency;
                if (fuelAtK < -EPS)
                    valid = false;
                else if (fuelAtK >= half - EPS) {
                    double nextPos = k + 1 < j ? d[k + 1] : target;
                    double need    = (nextPos - d[k]) / efficiency;
                    if (fuelAtK < need - EPS)
                        valid = false;
                }
            }
            if (!valid)
                continue;
            double fuelAtTarget = capacity - dis / efficiency;
            if (fuelAtTarget < -EPS)
                continue;
            if (fuelAtTarget < 0)
                fuelAtTarget = 0;
            if (j == n + 1)
                dp[i] = 0;
            else {
                bool canStop = fuelAtTarget < half - EPS;
                if (!canStop) {
                    double nextPos = j == n ? dist : d[j + 1];
                    double need    = (nextPos - d[j]) / efficiency;
                    if (fuelAtTarget < need - EPS)
                        canStop = true;
                }
                if (!canStop)
                    continue;
                double fuelToBuy = capacity - fuelAtTarget;
                double cost      = fuelToBuy * p[j];
                cost             = round(cost * 10.0 + EPS) / 10.0;
                cost += 20.0 + dp[j];
                if (cost < dp[i])
                    dp[i] = cost;
            }
        }
    }
}

void output() { printf("%.1f\n", initCost + dp[0]); }

int main() {
    input();
    process();
    output();
    return 0;
}
