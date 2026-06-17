#include <bits/stdc++.h>
using namespace std;

int n, val[26], order[30], oc;
char a[30], b[30], c[30];
bool used[30];

bool check() {
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v1 = val[a[i] - 'A'], v2 = val[b[i] - 'A'], v3 = val[c[i] - 'A'];
        if (v1 == -1 || v2 == -1 || v3 == -1) { carry = -1; continue; }
        if (carry == -1) carry = 0;
        if ((v1 + v2 + carry) % n != v3) return false;
        carry = (v1 + v2 + carry) / n;
    }
    return carry == 0;
}

bool prune() {
    for (int i = n - 1; i >= 0; --i) {
        int v1 = val[a[i] - 'A'], v2 = val[b[i] - 'A'], v3 = val[c[i] - 'A'];
        if (v1 == -1 || v2 == -1 || v3 == -1) continue;
        bool ok = false;
        for (int cr = 0; cr <= 1; ++cr)
            if ((v1 + v2 + cr) % n == v3) { ok = true; break; }
        if (!ok) return false;
    }
    return true;
}

bool dfs(int idx) {
    if (idx == oc) return check();
    int let = order[idx];
    for (int d = n - 1; d >= 0; --d) {
        if (used[d]) continue;
        val[let] = d; used[d] = true;
        if (prune() && dfs(idx + 1)) return true;
        used[d] = false; val[let] = -1;
    }
    return false;
}

int main() {
    scanf("%d%s%s%s", &n, a, b, c);
    memset(val, -1, sizeof(val));
    bool seen[26] = {false};
    oc = 0;
    for (int i = n - 1; i >= 0; --i) {
        int la = a[i] - 'A', lb = b[i] - 'A', lc = c[i] - 'A';
        if (!seen[la]) { seen[la] = true; order[oc++] = la; }
        if (!seen[lb]) { seen[lb] = true; order[oc++] = lb; }
        if (!seen[lc]) { seen[lc] = true; order[oc++] = lc; }
    }
    dfs(0);
    for (int i = 0; i < n; ++i) printf("%d%c", val[i], i == n - 1 ? '\n' : ' ');
    return 0;
}
