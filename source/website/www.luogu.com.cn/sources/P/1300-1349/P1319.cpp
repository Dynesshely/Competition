#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    int cur = 0, cnt = 0;
    while (scanf("%d", &x) == 1) {
        for (int i = 0; i < x; ++i) {
            printf("%d", cur);
            ++cnt;
            if (cnt % n == 0) printf("\n");
        }
        cur ^= 1;
    }
    return 0;
}
