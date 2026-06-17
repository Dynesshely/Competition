#include <bits/stdc++.h>
using namespace std;

char s[1024];

void dfs(int l, int r) {
    if (l == r) { putchar(s[l] == '0' ? 'B' : 'I'); return; }
    int mid = (l + r) / 2;
    dfs(l, mid); dfs(mid + 1, r);
    bool h0 = false, h1 = false;
    for (int i = l; i <= r; ++i) if (s[i] == '0') h0 = true; else h1 = true;
    putchar(h0 && h1 ? 'F' : (h0 ? 'B' : 'I'));
}

int main() {
    int n;
    scanf("%d%s", &n, s);
    dfs(0, (1 << n) - 1);
    putchar('\n');
    return 0;
}
