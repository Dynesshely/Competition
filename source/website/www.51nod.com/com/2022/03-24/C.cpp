#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int n, m, x, y, type, z, cnt, h[maxn], opt[maxn], val[maxn];
int fa[maxn], d[maxn], size[maxn], son[maxn], top[maxn];
int Time, in[maxn], out[maxn], pos[maxn];
int s[2][maxn << 1], struct edge {
    int to, ne;
} e[maxn << 1];
void add(int x, int y) {
    e[++cnt] = (edge){y, h[x]};
    h[x] = cnt;
}
void dfs1(int x) { int i, y; }
int main() { return 0; }
