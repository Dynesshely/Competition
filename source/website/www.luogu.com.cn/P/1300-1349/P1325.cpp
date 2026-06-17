#include <bits/stdc++.h>
using namespace std;

int                  n, d;
double               eps = 1e-6;
pair<double, double> intervals[1005];

void input() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y > d) {
            printf("-1\n");
            exit(0);
        }
        double t     = sqrt(1.0 * d * d - 1.0 * y * y);
        intervals[i] = {x - t, x + t};
    }
}

void process() {
    sort(intervals, intervals + n, [](const pair<double, double> &a, const pair<double, double> &b) { return a.second < b.second; });
}

void output() {
    int    ans = 0;
    double pos = -1e18;
    for (int i = 0; i < n; ++i) {
        if (intervals[i].first > pos + eps) {
            ++ans;
            pos = intervals[i].second;
        }
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
