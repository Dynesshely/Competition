#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int p_lines, k;
  cin >> p_lines >> k;
  string s, line;
  for (int i = 0; i < p_lines; ++i) {
    cin >> line;
    s += line;
  }
  int dict_size;
  cin >> dict_size;
  vector<string> dict(dict_size);
  for (int i = 0; i < dict_size; ++i) cin >> dict[i];

  int n = s.size();
  vector<int> min_end(n, n + 1);
  for (int i = 0; i < n; ++i)
    for (auto& w : dict)
      if (s.substr(i, w.size()) == w)
        min_end[i] = min(min_end[i], i + (int)w.size() - 1);

  vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
  for (int l = 1; l <= n; ++l)
    for (int r = l; r <= n; ++r)
      for (int i = l - 1; i < r; ++i)
        if (min_end[i] < r) ++cnt[l][r];

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; ++i) dp[i][1] = cnt[1][i];
  for (int j = 2; j <= k; ++j)
    for (int i = j; i <= n; ++i)
      for (int m = j - 1; m < i; ++m)
        dp[i][j] = max(dp[i][j], dp[m][j - 1] + cnt[m + 1][i]);

  cout << dp[n][k] << endl;
  return 0;
}
