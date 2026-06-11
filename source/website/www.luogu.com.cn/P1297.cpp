#include <bits/stdc++.h>
using namespace std;

int n, A, B, C, a1;

void input() { scanf("%d%d%d%d%d", &n, &A, &B, &C, &a1); }

void process() {
    double ans     = 0;
    int    rawPrev = a1;
    int    first   = a1 % C + 1;
    int    prev    = first;
    for (int i = 2; i <= n; i++) {
        int rawCurr = (1LL * rawPrev * A + B) % 100000001;
        int curr    = rawCurr % C + 1;
        ans += 1.0 / max(prev, curr);
        rawPrev = rawCurr;
        prev    = curr;
    }
    ans += 1.0 / max(first, prev);
    printf("%.3f\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
