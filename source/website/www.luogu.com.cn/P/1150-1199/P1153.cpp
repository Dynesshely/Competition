#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

vector<Point> pts;
int           n;
int           ans;

long long cross(const Point &a, const Point &b, const Point &c) { return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x); }

bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    long long s1 = cross(a, b, c);
    long long s2 = cross(a, b, d);
    long long s3 = cross(c, d, a);
    long long s4 = cross(c, d, b);
    return (s1 > 0) != (s2 > 0) && (s3 > 0) != (s4 > 0);
}

void input() {
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        pts.push_back({x, y});
        if (x == 0 && y == 0)
            break;
    }
    n = pts.size();
}

void process() {
    if (n <= 2) {
        ans = 0;
        return;
    }
    vector<int> perm(n - 1);
    for (int i = 0; i < n - 1; i++)
        perm[i] = i + 1;
    ans = 0;
    do {
        vector<int> cycle(n);
        cycle[0] = 0;
        for (int i = 0; i < n - 1; i++)
            cycle[i + 1] = perm[i];
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            int a = cycle[i], b = cycle[(i + 1) % n];
            for (int j = i + 2; j < n && ok; j++) {
                int c = cycle[j], d = cycle[(j + 1) % n];
                if (a == c || a == d || b == c || b == d)
                    continue;
                if (intersect(pts[a], pts[b], pts[c], pts[d]))
                    ok = false;
            }
        }
        if (ok)
            ans++;
    } while (next_permutation(perm.begin(), perm.end()));
    ans /= 2;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
