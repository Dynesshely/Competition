#include <bits/stdc++.h>

using namespace std;

bool vis[100];
int ele[6] = {2, 3, 5, 7, 10, 15};

void reach(int index) { vis[index] = true; }

int main() {

  memset(vis, 0, sizeof(vis));

  for (int i = 0; i < 6; ++i)
    reach(ele[i]);

  for (int i = 0; i < 6; ++i)
    for (int j = i; j < 6; ++j)
      reach(ele[i] + ele[j]);

  for (int i = 0; i < 6; ++i)
    for (int j = i; j < 6; ++j)
      for (int k = j; k < 6; ++k)
        reach(ele[i] + ele[j] + ele[k]);

  for (int i = 0; i < 6; ++i)
    for (int j = i; j < 6; ++j)
      for (int k = j; k < 6; ++k)
        for (int l = k; l < 6; ++l)
          reach(ele[i] + ele[j] + ele[k] + ele[l]);

  for (int i = 0; i < 6; ++i)
    for (int j = i; j < 6; ++j)
      for (int k = j; k < 6; ++k)
        for (int l = k; l < 6; ++l)
          for (int m = l; m < 6; ++m)
            reach(ele[i] + ele[j] + ele[k] + ele[l] + ele[m]);

  reach(2 + 3 + 5 + 7 + 10 + 15);

  int result = 0;

  for (int i = 0; i < 100; ++i) {
    if (vis[i])
      result += 1;
  }

  cout << result << endl;

  return 0;
}
