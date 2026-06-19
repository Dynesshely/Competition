#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    int cntA = 0, cntB = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, cnt1 = 0, cnt0 = 0;
        while (x) {
            if (x & 1)
                cnt1++;
            else
                cnt0++;
            x >>= 1;
        }
        if (cnt1 > cnt0)
            cntA++;
        else
            cntB++;
    }
    printf("%d %d\n", cntA, cntB);
}

int main() {
    input();
    process();
    return 0;
}
