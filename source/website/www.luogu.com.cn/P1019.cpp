#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans;
vector<string> w;
vector<int> cnt;
vector<vector<int>> ov;

int calc_overlap(const string& a, const string& b) {
  size_t mx = min(a.size(), b.size());
  for (size_t len = 1; len <= mx; ++len)
    if (a.substr(a.size() - len) == b.substr(0, len)) return len;
  return 0;
}

void dfs(int last, int len) {
  ans = max(ans, len);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= 2) continue;
    int o = ov[last][i];
    if (o > 0 && o < (int)w[last].size() && o < (int)w[i].size()) {
      ++cnt[i];
      dfs(i, len + w[i].size() - o);
      --cnt[i];
    }
  }
}

int main() {
  cin >> n;
  w.resize(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  char start;
  cin >> start;
  ov.assign(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      ov[i][j] = calc_overlap(w[i], w[j]);
  cnt.assign(n, 0);
  ans = 0;
  for (int i = 0; i < n; ++i) {
    if (w[i][0] == start) {
      cnt[i] = 1;
      dfs(i, w[i].size());
      cnt[i] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
