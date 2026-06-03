#include <bits/stdc++.h>
using namespace std;

char comet[8], group[8];

int calc(char *s) {
  int res = 1;
  for (int i = 0; s[i]; i++)
    res = res * (s[i] - 'A' + 1) % 47;
  return res;
}

int main() {
  scanf("%s%s", comet, group);
  if (calc(comet) == calc(group))
    printf("GO\n");
  else
    printf("STAY\n");
  return 0;
}
