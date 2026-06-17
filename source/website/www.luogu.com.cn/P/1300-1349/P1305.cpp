#include <bits/stdc++.h>
using namespace std;

int  n, l[128], r[128];
char root;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char p, lc, rc;
        scanf(" %c %c %c", &p, &lc, &rc);
        if (i == 0)
            root = p;
        l[p] = (lc == '*' ? 0 : lc);
        r[p] = (rc == '*' ? 0 : rc);
    }
}

void dfs(char u) {
    if (u == 0)
        return;
    putchar(u);
    dfs(l[u]);
    dfs(r[u]);
}

void output() {
    dfs(root);
    putchar('\n');
}

int main() {
    input();
    output();
    return 0;
}
