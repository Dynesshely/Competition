#include <bits/stdc++.h>
using namespace std;

int       n;
long long ans[10];

void input() { scanf("%d", &n); }

void process() {
    for (int factor = 1; factor <= n; factor *= 10) {
        int higher = n / (factor * 10);
        int cur    = (n / factor) % 10;
        int lower  = n % factor;

        for (int d = 1; d <= 9; d++) {
            ans[d] += (long long)higher * factor;
            if (cur > d)
                ans[d] += factor;
            else if (cur == d)
                ans[d] += lower + 1;
        }

        if (higher > 0) {
            ans[0] += (long long)(higher - 1) * factor;
            if (cur > 0)
                ans[0] += factor;
            else
                ans[0] += lower + 1;
        }
    }
}

void output() {
    for (int i = 0; i < 10; i++)
        printf("%lld\n", ans[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
