#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, k, mis;
int nxt[MAXN], col[MAXN];

void input() {
    scanf("%d%d", &n, &k);
    mis     = 0;
    int cur = 1;
    for (int i = 0; i < k; i++) {
        int s;
        scanf("%d", &s);
        for (int j = 0; j < s; j++) {
            int pos;
            scanf("%d", &pos);
            int tgt = cur + j;
            if (pos != tgt) {
                nxt[pos] = tgt;
                mis++;
            }
        }
        cur += s;
    }
}

void process() {
    int cyc = 0;
    for (int i = 1; i <= n; i++) {
        if (!nxt[i] || col[i])
            continue;
        int p = i;
        while (p && !col[p]) {
            col[p] = 1;
            p      = nxt[p];
        }
        if (p && col[p] == 1)
            cyc++;
        p = i;
        while (p && col[p] == 1) {
            col[p] = 2;
            p      = nxt[p];
        }
    }
    mis += cyc;
}

void output() {
    if (mis)
        printf("We need %d move operations.\n", mis);
    else
        printf("No optimization needed.\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
