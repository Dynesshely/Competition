#include <bits/stdc++.h>
using namespace std;

int       n;
char      s[100005];
long long preN[100005], sufI[100005];
long long ans, bestGain;

void input() { scanf("%d%s", &n, s + 1); }

void process() {
    preN[0] = 0;
    for (int i = 1; i <= n; ++i)
        preN[i] = preN[i - 1] + (s[i] == 'N');
    sufI[n + 1] = 0;
    for (int i = n; i >= 1; --i)
        sufI[i] = sufI[i + 1] + (s[i] == 'I');
    long long cntN = 0, cntNO = 0;
    for (int i = 1; i <= n; ++i)
        if (s[i] == 'N')
            ++cntN;
        else if (s[i] == 'O') {
            ans += preN[i - 1] * sufI[i + 1];
            cntNO += cntN;
        }
    long long cntI = 0, cntOI = 0;
    for (int i = n; i >= 1; --i)
        if (s[i] == 'I')
            ++cntI;
        else if (s[i] == 'O')
            cntOI += cntI;
    bestGain = cntOI;
    if (cntNO > bestGain)
        bestGain = cntNO;
    for (int i = 1; i <= n + 1; ++i) {
        long long cur = preN[i - 1] * sufI[i];
        if (cur > bestGain)
            bestGain = cur;
    }
    ans += bestGain;
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
