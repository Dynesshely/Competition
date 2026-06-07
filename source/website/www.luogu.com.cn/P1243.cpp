#include <bits/stdc++.h>
using namespace std;

int         n;
long long   k;
vector<int> ans;

void solve(int start, long long k) {
    if (k == 1)
        return;
    k--;
    for (int m = start; m <= n; m++) {
        long long cnt = 1LL << (n - m);
        if (k <= cnt) {
            ans.push_back(m);
            solve(m + 1, k);
            return;
        }
        k -= cnt;
    }
}

void input() { scanf("%d%lld", &n, &k); }

void process() { solve(1, k); }

void output() {
    if (ans.empty()) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
