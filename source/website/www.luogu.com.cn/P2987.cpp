#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

static const double EPS = 1e-9;

bool inside(const Point &p, double A, double B, double C) { return A * p.x + B * p.y - C <= EPS; }

Point intersectSegHalfplane(const Point &s, const Point &e, double A, double B, double C) {
    double ds = C - (A * s.x + B * s.y);
    double de = C - (A * e.x + B * e.y);
    double t  = ds / (ds - de);

    Point r;
    r.x = s.x + (e.x - s.x) * t;
    r.y = s.y + (e.y - s.y) * t;
    return r;
}

vector<Point> clipPolygon(const vector<Point> &poly, double A, double B, double C) {
    vector<Point> res;
    int           n = (int)poly.size();
    if (n == 0)
        return res;

    for (int i = 0; i < n; i++) {
        Point S = poly[i];
        Point E = poly[(i + 1) % n];

        bool inS = inside(S, A, B, C);
        bool inE = inside(E, A, B, C);

        if (inS && inE) {
            res.push_back(E);
        } else if (inS && !inE) {
            res.push_back(intersectSegHalfplane(S, E, A, B, C));
        } else if (!inS && inE) {
            res.push_back(intersectSegHalfplane(S, E, A, B, C));
            res.push_back(E);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    struct HP {
        double A, B, C;   // A*x + B*y <= C
    };

    vector<HP> hps;

    // x,y bounds
    hps.push_back({1, 0, 100.0});    // x <= 100
    hps.push_back({-1, 0, -0.01});   // x >= 0.01
    hps.push_back({0, 1, 100.0});    // y <= 100
    hps.push_back({0, -1, -0.01});   // y >= 0.01

    // pairwise ratio bounds
    hps.push_back({1, -100, 0.0});   // x <= 100y
    hps.push_back({-100, 1, 0.0});   // y <= 100x

    for (int i = 0; i < N; i++) {
        char      V;
        long long J1, J2, J3, B1, B2, B3;
        cin >> V >> J1 >> J2 >> J3 >> B1 >> B2 >> B3;

        long long a = J1 - B1;
        long long b = J2 - B2;
        long long c = J3 - B3;

        if (V == 'J') {
            // a + b*x + c*y >= 0
            // -b*x - c*y <= a
            hps.push_back({-(double)b, -(double)c, (double)a});
        } else {
            // a + b*x + c*y <= 0
            // b*x + c*y <= -a
            hps.push_back({(double)b, (double)c, -(double)a});
        }
    }

    vector<array<long long, 6>> queries(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 6; j++)
            cin >> queries[i][j];
    }

    vector<Point> poly = {{0.01, 0.01}, {100.0, 0.01}, {100.0, 100.0}, {0.01, 100.0}};

    for (auto &hp : hps) {
        poly = clipPolygon(poly, hp.A, hp.B, hp.C);
    }

    for (int i = 0; i < M; i++) {
        auto &q = queries[i];

        long long a = q[0] - q[3];
        long long b = q[1] - q[4];
        long long c = q[2] - q[5];

        double mn = 1e100;
        double mx = -1e100;

        for (auto &p : poly) {
            double v = (double)a + (double)b * p.x + (double)c * p.y;
            mn       = min(mn, v);
            mx       = max(mx, v);
        }

        if (mn > EPS) {
            cout << "J\n";
        } else if (mx < -EPS) {
            cout << "B\n";
        } else {
            cout << "U\n";
        }
    }

    return 0;
}