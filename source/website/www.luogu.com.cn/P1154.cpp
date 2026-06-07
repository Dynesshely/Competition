#include <bits/stdc++.h>
using namespace std;

int  n, s[5010], ans;
bool hasDiff[1000010];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
}

void process() {
    int maxS = *max_element(s, s + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            hasDiff[abs(s[i] - s[j])] = true;
    for (int k = n; k <= maxS; k++) {
        bool ok = true;
        for (int m = k; m <= maxS; m += k)
            if (hasDiff[m]) {
                ok = false;
                break;
            }
        if (ok) {
            ans = k;
            return;
        }
    }
    ans = maxS + 1;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
