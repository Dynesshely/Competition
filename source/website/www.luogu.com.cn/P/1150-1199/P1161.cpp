#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int ip, fp;
        scanf("%d.%d", &ip, &fp);
        int a = ip * 1000000 + fp;
        int t;
        scanf("%d", &t);
        for (int j = 1; j <= t; ++j) {
            int pos = (long long)j * a / 1000000;
            ans ^= pos;
        }
    }
    printf("%d\n", ans);
    return 0;
}
