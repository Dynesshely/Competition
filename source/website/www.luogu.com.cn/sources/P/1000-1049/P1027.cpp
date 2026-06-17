#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};
struct City {
  Point ap[4];
  double train_cost;
};

Point fourth_point(Point a, Point b, Point c) {
  double ab = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  double ac = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
  double bc = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
  if (fabs(ab + ac - bc) < 1e-6) return {b.x + c.x - a.x, b.y + c.y - a.y};
  if (fabs(ab + bc - ac) < 1e-6) return {a.x + c.x - b.x, a.y + c.y - b.y};
  return {a.x + b.x - c.x, a.y + b.y - c.y};
}

double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  int T;
  cin >> T;
  cout << fixed << setprecision(1);
  while (T--) {
    int S, A, B;
    double t;
    cin >> S >> t >> A >> B;
    --A, --B;
    vector<City> cities(S);
    for (int i = 0; i < S; ++i) {
      double x1, y1, x2, y2, x3, y3, ti;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> ti;
      cities[i].ap[0] = {x1, y1};
      cities[i].ap[1] = {x2, y2};
      cities[i].ap[2] = {x3, y3};
      cities[i].ap[3] = fourth_point({x1, y1}, {x2, y2}, {x3, y3});
      cities[i].train_cost = ti;
    }
    int V = S * 4;
    vector<vector<double>> g(V, vector<double>(V, 1e18));
    for (int i = 0; i < V; ++i) g[i][i] = 0;
    for (int i = 0; i < S; ++i) {
      for (int a = 0; a < 4; ++a) {
        for (int b = a + 1; b < 4; ++b) {
          double d = dist(cities[i].ap[a], cities[i].ap[b]);
          g[i * 4 + a][i * 4 + b] = d * cities[i].train_cost;
          g[i * 4 + b][i * 4 + a] = d * cities[i].train_cost;
        }
      }
    }
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        if (i == j) continue;
        for (int a = 0; a < 4; ++a) {
          for (int b = 0; b < 4; ++b) {
            double d = dist(cities[i].ap[a], cities[j].ap[b]);
            g[i * 4 + a][j * 4 + b] = d * t;
          }
        }
      }
    }
    for (int k = 0; k < V; ++k)
      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    double ans = 1e18;
    for (int a = 0; a < 4; ++a)
      for (int b = 0; b < 4; ++b)
        ans = min(ans, g[A * 4 + a][B * 4 + b]);
    cout << ans << endl;
  }
  return 0;
}
