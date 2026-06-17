#include <bits/stdc++.h>
using namespace std;

int  n, target, c[13], perm[13];
bool used[13];

void input() { scanf("%d%d", &n, &target); }

void process() {
    for (int i = 0; i < n; i++) {
        int val = 1;
        for (int j = 1; j <= i; j++)
            val = val * (n - j) / j;
        c[i] = val;
    }
}

bool dfs(int pos, int sum) {
    if (pos == n)
        return sum == target;
    int rem[13], cnt = 0;
    for (int v = 1; v <= n; v++)
        if (!used[v])
            rem[cnt++] = v;
    int coeff[13];
    for (int i = pos; i < n; i++)
        coeff[i - pos] = c[i];
    sort(coeff, coeff + cnt);
    sort(rem, rem + cnt);
    int minAdd = 0, maxAdd = 0;
    for (int i = 0; i < cnt; i++) {
        minAdd += coeff[i] * rem[cnt - 1 - i];
        maxAdd += coeff[i] * rem[i];
    }
    if (sum + minAdd > target || sum + maxAdd < target)
        return false;
    for (int v = 1; v <= n; v++) {
        if (used[v])
            continue;
        int nxt = sum + v * c[pos];
        if (nxt > target)
            break;
        used[v]   = true;
        perm[pos] = v;
        if (dfs(pos + 1, nxt))
            return true;
        used[v] = false;
    }
    return false;
}

void output() {
    for (int i = 0; i < n; i++) {
        if (i)
            printf(" ");
        printf("%d", perm[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    dfs(0, 0);
    output();
    return 0;
}
