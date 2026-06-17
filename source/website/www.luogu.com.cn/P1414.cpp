#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXV = 1000005;

int n, maxVal, a[MAXN], freq[MAXV], cnt[MAXV], best[MAXN], ans[MAXN];

void input() {
    scanf("%d", &n);
    maxVal = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > maxVal)
            maxVal = a[i];
        freq[a[i]]++;
    }
}

void process() {
    for (int d = 1; d <= maxVal; ++d)
        for (int j = d; j <= maxVal; j += d)
            cnt[d] += freq[j];
    for (int d = 1; d <= maxVal; ++d)
        if (cnt[d] > 0 && d > best[cnt[d]])
            best[cnt[d]] = d;
    ans[n + 1] = 0;
    for (int k = n; k >= 1; --k)
        ans[k] = max(ans[k + 1], best[k]);
}

void output() {
    for (int k = 1; k <= n; ++k)
        printf("%d\n", ans[k]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
