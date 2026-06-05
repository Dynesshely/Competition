#include <bits/stdc++.h>
using namespace std;

int         n;
vector<int> a;
int         ans;

void input() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void process() {
    int         size = 2 * n + 1;
    vector<int> firstPos(size, -2);
    firstPos[n] = -1;
    int pref    = 0;
    ans         = 0;
    for (int i = 0; i < n; i++) {
        pref += (a[i] == 0 ? -1 : 1);
        int idx = pref + n;
        if (firstPos[idx] != -2) {
            ans = max(ans, i - firstPos[idx]);
        } else {
            firstPos[idx] = i;
        }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
