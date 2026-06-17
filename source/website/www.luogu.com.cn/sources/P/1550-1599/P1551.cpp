#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int fa[MAXN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        fa[find(x)] = find(y);
    }
    while (p--) {
        int x, y;
        scanf("%d%d", &x, &y);
        puts(find(x) == find(y) ? "Yes" : "No");
    }
    return 0;
}
