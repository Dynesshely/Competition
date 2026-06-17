#include <bits/stdc++.h>
using namespace std;

int n, total;
int col[14], diag1[30], diag2[30], ans[14];

void dfs(int r) {
    if (r > n) {
        total++;
        if (total <= 3) {
            for (int i = 1; i <= n; i++) {
                if (i > 1)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int c = 1; c <= n; c++) {
        int d1 = r - c + n;
        int d2 = r + c;
        if (col[c] || diag1[d1] || diag2[d2])
            continue;
        col[c] = diag1[d1] = diag2[d2] = 1;
        ans[r]                         = c;
        dfs(r + 1);
        col[c] = diag1[d1] = diag2[d2] = 0;
    }
}

void input() { scanf("%d", &n); }

void process() { dfs(1); }

void output() { printf("%d\n", total); }

int main() {
    input();
    process();
    output();
    return 0;
}
