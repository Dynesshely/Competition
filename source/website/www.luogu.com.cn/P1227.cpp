#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool cmp(Point a, Point b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int   n;
Point p[20005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

void process() {
    sort(p, p + n, cmp);
    int sumX = p[0].x + p[n - 1].x;
    int sumY = p[0].y + p[n - 1].y;
    for (int i = 1; i < n; i++) {
        if (p[i].x + p[n - 1 - i].x != sumX || p[i].y + p[n - 1 - i].y != sumY) {
            printf("This is a dangerous situation!\n");
            return;
        }
    }
    double cx = sumX / 2.0;
    double cy = sumY / 2.0;
    printf("V.I.P. should stay at (%.1f,%.1f).\n", cx, cy);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
