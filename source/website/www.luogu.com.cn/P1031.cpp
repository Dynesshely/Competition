#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int avg = sum / n, ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != avg) {
      a[i + 1] += a[i] - avg;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
