#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a;
  int x;
  while (cin >> x) a.push_back(x);
  int n = a.size();

  vector<int> tails;
  for (int i = 0; i < n; ++i) {
    int v = -a[i];
    auto it = upper_bound(tails.begin(), tails.end(), v);
    if (it == tails.end()) tails.push_back(v);
    else *it = v;
  }
  cout << tails.size() << endl;

  tails.clear();
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(tails.begin(), tails.end(), a[i]);
    if (it == tails.end()) tails.push_back(a[i]);
    else *it = a[i];
  }
  cout << tails.size() << endl;

  return 0;
}
