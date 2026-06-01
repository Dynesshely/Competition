#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double H, S1, V, L, K;
  int n;
  cin >> H >> S1 >> V >> L >> K >> n;
  double t1 = sqrt((H - K) / 5.0);
  double t2 = sqrt(H / 5.0);
  const double eps = 1e-4;
  int right = (int)floor(S1 + L - V * t1 + eps);
  int left = (int)ceil(S1 - V * t2 - eps);
  right = min(right, n - 1);
  left = max(left, 0);
  cout << max(0, right - left + 1) << endl;
  return 0;
}
