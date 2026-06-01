#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> f(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    int sum = 1;
    for (int j = 1; j <= i / 2; ++j) sum += f[j];
    f[i] = sum;
  }
  cout << f[n] << endl;
  return 0;
}
