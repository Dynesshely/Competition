#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct Pt {
  int x, y;
};
struct Rect {
  int x1, y1, x2, y2;
  bool empty;
  Rect() : x1(INT_MAX), y1(INT_MAX), x2(INT_MIN), y2(INT_MIN), empty(true) {}
  void add(const Pt& p) {
    if (empty) { x1 = x2 = p.x; y1 = y2 = p.y; empty = false; }
    else { x1 = min(x1, p.x); y1 = min(y1, p.y);
           x2 = max(x2, p.x); y2 = max(y2, p.y); }
  }
  int area() const { return empty ? 0 : (x2 - x1) * (y2 - y1); }
};

bool overlap(const Rect& a, const Rect& b) {
  if (a.empty || b.empty) return false;
  return !(a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1);
}

int n, k, best;
vector<Pt> pts;

void dfs(int idx, vector<Rect>& rects, int used) {
  if (idx == n) {
    int sum = 0;
    for (auto& r : rects) sum += r.area();
    best = min(best, sum);
    return;
  }
  int cur = 0;
  for (auto& r : rects) cur += r.area();
  if (cur >= best) return;

  for (int i = 0; i < used; ++i) {
    Rect old = rects[i];
    rects[i].add(pts[idx]);
    bool ok = true;
    for (int j = 0; j < used && ok; ++j)
      if (i != j && overlap(rects[i], rects[j])) ok = false;
    if (ok) dfs(idx + 1, rects, used);
    rects[i] = old;
  }

  if (used < k) {
    rects[used] = Rect();
    rects[used].add(pts[idx]);
    dfs(idx + 1, rects, used + 1);
    rects[used] = Rect();
  }
}

int main() {
  cin >> n >> k;
  pts.resize(n);
  for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
  sort(pts.begin(), pts.end(), [](const Pt& a, const Pt& b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
  });
  best = INT_MAX;
  vector<Rect> rects(k);
  dfs(0, rects, 0);
  cout << best << endl;
  return 0;
}
