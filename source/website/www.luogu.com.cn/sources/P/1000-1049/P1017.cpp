#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, R;
  cin >> n >> R;
  cout << n << "=";
  string ans;
  const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (n != 0) {
    int r = n % R;
    n /= R;
    if (r < 0) {
      r -= R;
      n += 1;
    }
    ans += digits[r];
  }
  if (ans.empty()) ans = "0";
  reverse(ans.begin(), ans.end());
  cout << ans << "(base" << R << ")" << endl;
  return 0;
}
