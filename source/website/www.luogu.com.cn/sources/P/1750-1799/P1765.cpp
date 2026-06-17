#include <bits/stdc++.h>
using namespace std;

int presses[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
  char s[210];
  fgets(s, 210, stdin);
  int ans = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == ' ') ++ans;
    else if (s[i] >= 'a' && s[i] <= 'z') ans += presses[s[i] - 'a'];
  }
  printf("%d\n", ans);
  return 0;
}
