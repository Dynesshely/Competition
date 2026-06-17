#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point p[200005], tmp[200005];
int   n;

double dist(const Point &a, const Point &b) {
    long long dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool cmpX(const Point &a, const Point &b) { return a.x < b.x; }

bool cmpY(const Point &a, const Point &b) { return a.y < b.y; }

double solve(int l, int r) {
    if (l >= r)
        return 1e100;
    if (r - l == 1)
        return dist(p[l], p[r]);
    int    mid  = (l + r) / 2;
    int    midX = p[mid].x;
    double d    = min(solve(l, mid), solve(mid + 1, r));
    int    cnt  = 0;
    for (int i = l; i <= r; i++)
        if (abs(p[i].x - midX) < d)
            tmp[cnt++] = p[i];
    sort(tmp, tmp + cnt, cmpY);
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt && tmp[j].y - tmp[i].y < d; j++)
            d = min(d, dist(tmp[i], tmp[j]));
    return d;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

void process() { sort(p, p + n, cmpX); }

void output() { printf("%.4lf\n", solve(0, n - 1)); }

int main() {
    input();
    process();
    output();
    return 0;
}
