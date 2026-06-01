#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int expected, cost, base_vol;
  cin >> expected >> cost >> base_vol;
  map<int, int> known;
  known[cost] = base_vol;
  int p, v;
  while (cin >> p >> v && !(p == -1 && v == -1)) known[p] = v;
  int dec;
  cin >> dec;

  int max_price = known.rbegin()->first;
  vector<pair<int, int>> table;
  for (int price = cost; ; ++price) {
    if (known.count(price)) {
      table.push_back({price, known[price]});
    } else if (price > max_price) {
      int last_vol = table.back().second;
      int vol = last_vol - dec * (price - max_price - 1);
      int cur = last_vol - dec;
      if (cur <= 0) break;
      table.push_back({price, cur});
    } else {
      auto it = known.upper_bound(price);
      int p2 = it->first, v2 = it->second;
      --it;
      int p1 = it->first, v1 = it->second;
      int vol = v1 + (v2 - v1) * (price - p1) / (p2 - p1);
      table.push_back({price, vol});
    }
  }

  const double INF = 1e18;
  double lo = -INF, hi = INF;
  int ev = 0;
  for (auto& kv : table)
    if (kv.first == expected) ev = kv.second;
  if (ev == 0) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  for (auto& kv : table) {
    int price = kv.first, vol = kv.second;
    if (price == expected) continue;
    long long num =
        (long long)(price - cost) * vol - (long long)(expected - cost) * ev;
    long long den = (long long)ev - vol;
    if (den == 0) {
      if (num > 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      continue;
    }
    double bound = (double)num / den;
    if (den > 0)
      lo = max(lo, bound);
    else
      hi = min(hi, bound);
  }

  if (lo > hi) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  if (lo <= 0 && hi >= 0)
    cout << 0 << endl;
  else if (hi < 0)
    cout << (int)floor(hi) << endl;
  else
    cout << (int)ceil(lo) << endl;
  return 0;
}
