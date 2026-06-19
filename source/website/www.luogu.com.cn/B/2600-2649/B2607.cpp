#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 1;
    for (int i = 0; i < 3; ++i)
        ans = (ans + 1) * 2;
    printf("%d\n", ans);
    return 0;
}
