#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct State { int len, link, nxt[26]; } st[MAXN];
int sz, last;
void sa_init() {
    st[0].len = 0; st[0].link = -1; sz = 1; last = 0;
    memset(st[0].nxt, -1, sizeof(st[0].nxt));
}
void sa_extend(char c) {
    int cur = sz++, v = c - 'A';
    memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && st[p].nxt[v] == -1) { st[p].nxt[v] = cur; p = st[p].link; }
    if (p == -1) st[cur].link = 0;
    else {
        int q = st[p].nxt[v];
        if (st[p].len + 1 == st[q].len) st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
            while (p != -1 && st[p].nxt[v] == q) { st[p].nxt[v] = clone; p = st[p].link; }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
char s[MAXN], t[MAXN];
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int pn = 0, pm = 0;
    while (pn < n) { char c; scanf(" %c", &c); if (c != '\n') s[pn++] = c; }
    while (pm < m) { char c; scanf(" %c", &c); if (c != '\n') t[pm++] = c; }
    s[n] = t[m] = '\0';
    sa_init();
    for (int i = 0; i < n; ++i) sa_extend(s[i]);
    int ans = 1, v = 0;
    for (int i = 0; i < m; ++i) {
        int c = t[i] - 'A';
        if (st[v].nxt[c] != -1) v = st[v].nxt[c];
        else if (st[0].nxt[c] != -1) { ans++; v = st[0].nxt[c]; }
        else { printf("-1\n"); return 0; }
    }
    printf("%d\n", ans);
    return 0;
}
