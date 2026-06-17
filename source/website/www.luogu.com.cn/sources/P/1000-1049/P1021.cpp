#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
int best_max;
vector<int> best_denom;

int max_coverage(const vector<int>& denom) {
  int limit = N * denom.back() + 10;
  vector<int> dp(limit + 1, 1e9);
  dp[0] = 0;
  int i;
  for (i = 1; i <= limit; ++i) {
    int mn = 1e9;
    for (int d : denom)
      if (i >= d) mn = min(mn, dp[i - d] + 1);
    if (mn > N) break;
    dp[i] = mn;
  }
  return i - 1;
}

void dfs(int depth, int prev, int cur_max, vector<int>& denom) {
  if (depth == K) {
    if (cur_max > best_max) {
      best_max = cur_max;
      best_denom = denom;
    }
    return;
  }
  for (int d = prev + 1; d <= cur_max + 1; ++d) {
    denom.push_back(d);
    int new_max = max_coverage(denom);
    dfs(depth + 1, d, new_max, denom);
    denom.pop_back();
  }
}

int main() {
  cin >> N >> K;
  vector<int> denom = {1};
  best_max = N;
  best_denom = {1};
  dfs(1, 1, N, denom);
  for (size_t i = 0; i < best_denom.size(); ++i) {
    if (i) cout << " ";
    cout << best_denom[i];
  }
  cout << "\nMAX=" << best_max << endl;
  return 0;
}
