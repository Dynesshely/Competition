#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BigInt {
  vector<int> d;
  BigInt() { d.push_back(0); }
  BigInt(const string& s) {
    for (int i = s.size() - 1; i >= 0; --i) d.push_back(s[i] - '0');
    if (d.empty()) d.push_back(0);
  }
  BigInt operator*(const BigInt& b) const {
    BigInt res;
    res.d.assign(d.size() + b.d.size(), 0);
    for (size_t i = 0; i < d.size(); ++i)
      for (size_t j = 0; j < b.d.size(); ++j)
        res.d[i + j] += d[i] * b.d[j];
    for (size_t i = 0; i < res.d.size(); ++i) {
      if (res.d[i] >= 10) {
        if (i + 1 == res.d.size()) res.d.push_back(0);
        res.d[i + 1] += res.d[i] / 10;
        res.d[i] %= 10;
      }
    }
    while (res.d.size() > 1 && res.d.back() == 0) res.d.pop_back();
    return res;
  }
  bool operator<(const BigInt& b) const {
    if (d.size() != b.d.size()) return d.size() < b.d.size();
    for (int i = d.size() - 1; i >= 0; --i)
      if (d[i] != b.d[i]) return d[i] < b.d[i];
    return false;
  }
};

int main() {
  int N, K;
  string s;
  cin >> N >> K >> s;
  vector<vector<BigInt>> dp(N + 1, vector<BigInt>(K + 1, BigInt("0")));
  for (int i = 1; i <= N; ++i) dp[i][0] = BigInt(s.substr(0, i));
  for (int k = 1; k <= K; ++k)
    for (int i = k + 1; i <= N; ++i) {
      BigInt best("0");
      for (int j = k; j < i; ++j) {
        BigInt cur = dp[j][k - 1] * BigInt(s.substr(j, i - j));
        if (best < cur) best = cur;
      }
      dp[i][k] = best;
    }
  for (int i = dp[N][K].d.size() - 1; i >= 0; --i)
    cout << dp[N][K].d[i];
  cout << endl;
  return 0;
}
