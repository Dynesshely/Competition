#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      if (i >= j) dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
  cout << dp[n][k] << endl;
  return 0;
}
