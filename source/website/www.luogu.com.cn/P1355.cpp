#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int cross(const Point &a, const Point &b, const Point &c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

int dot(const Point &a, const Point &b, const Point &p) { return (a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y); }

Point readPoint() {
    int x, y;
    scanf(" (%d,%d)", &x, &y);
    return {x, y};
}

int main() {
    Point a = readPoint();
    Point b = readPoint();
    Point c = readPoint();
    Point p = readPoint();

    if ((p.x == a.x && p.y == a.y) || (p.x == b.x && p.y == b.y) || (p.x == c.x && p.y == c.y)) {
        printf("4\n");
        return 0;
    }

    if (cross(a, b, p) == 0 && dot(a, b, p) <= 0) {
        printf("3\n");
        return 0;
    }
    if (cross(b, c, p) == 0 && dot(b, c, p) <= 0) {
        printf("3\n");
        return 0;
    }
    if (cross(c, a, p) == 0 && dot(c, a, p) <= 0) {
        printf("3\n");
        return 0;
    }

    if (cross(a, b, c) < 0)
        swap(b, c);

    bool inside = cross(a, b, p) > 0 && cross(b, c, p) > 0 && cross(c, a, p) > 0;

    printf("%d\n", inside ? 1 : 2);

    return 0;
}
