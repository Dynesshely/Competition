#include <bits/stdc++.h>
using namespace std;

int  n, p;
char s[10010], ans[10010];
int  cnt[26], st[26], occ[26];

void input() { scanf("%d%s%d", &n, s, &p); }

void process() {
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    for (int i = 1; i < 26; i++)
        st[i] = st[i - 1] + cnt[i - 1];
    int pos  = 0;
    ans[pos] = s[p - 1];
    for (int i = 1; i < n; i++) {
        int c    = ans[pos] - 'a';
        int prv  = (pos - 1 + n) % n;
        ans[prv] = s[st[c] + occ[c]];
        occ[c]++;
        pos = prv;
    }
}

void output() { printf("%s\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
