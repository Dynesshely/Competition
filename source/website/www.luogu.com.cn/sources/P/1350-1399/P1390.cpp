#include <bits/stdc++.h>
using namespace std;

int       n;
long long ans;

void input() { scanf("%d", &n); }

void process() {
    vector<int> phi(n + 1);
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + phi[i];
    for (int d = 1; d <= n; d++) {
        int m = n / d;
        ans += (long long)d * (pref[m] - 1);
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
