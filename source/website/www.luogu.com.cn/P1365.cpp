#include <bits/stdc++.h>
using namespace std;

int         n;
char        s[300010];
long double ans;

void input() { scanf("%d%s", &n, s); }

void process() {
    long double len = 0;
    ans             = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            ans += 2 * len + 1;
            len = len + 1;
        } else if (s[i] == 'x') {
            len = 0;
        } else {
            ans += (2 * len + 1) / 2;
            len = (len + 1) / 2;
        }
    }
}

void output() { printf("%.4Lf\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
