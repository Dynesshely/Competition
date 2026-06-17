#include <bits/stdc++.h>
using namespace std;

int       n;
int       pos[46], tar[46];
long long ans;

void dfs(int k, int to) {
    if (k == 0)
        return;
    int from = pos[k];
    if (from == to) {
        dfs(k - 1, to);
        return;
    }
    int aux = 6 - from - to;
    dfs(k - 1, aux);
    printf("move %d from %c to %c\n", k, 'A' + from - 1, 'A' + to - 1);
    pos[k] = to;
    ans++;
    dfs(k - 1, to);
}

void input() {
    scanf("%d", &n);
    for (int p = 1; p <= 3; p++) {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            pos[x] = p;
        }
    }
    for (int p = 1; p <= 3; p++) {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            tar[x] = p;
        }
    }
}

void process() {
    for (int i = n; i >= 1; i--)
        if (pos[i] != tar[i]) {
            int aux = 6 - pos[i] - tar[i];
            dfs(i - 1, aux);
            printf("move %d from %c to %c\n", i, 'A' + pos[i] - 1, 'A' + tar[i] - 1);
            pos[i] = tar[i];
            ans++;
        }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
