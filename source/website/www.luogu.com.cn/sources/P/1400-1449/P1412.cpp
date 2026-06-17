#include <bits/stdc++.h>
using namespace std;

int n, k, c, w;
int typ[100005];
int val[100005];

void input() {
    scanf("%d%d%d%d", &n, &k, &c, &w);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &typ[i], &val[i]);
}

void process() {
    double kRate = 1.0 - 0.01 * k;
    double cRate = 1.0 + 0.01 * c;
    double dp    = 0.0;
    for (int i = n - 1; i >= 0; i--) {
        if (typ[i] == 1)
            dp = max(dp, val[i] + kRate * dp);
        else
            dp = max(dp, -val[i] + cRate * dp);
    }
    printf("%.2f\n", w * dp);
}

int main() {
    input();
    process();
    return 0;
}
