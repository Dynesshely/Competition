#include <bits/stdc++.h>
using namespace std;

const int N = 40005;

int         n, ans;
char        s[N];
vector<int> g[N];
int         imxR[N], imxL[N], omxR[N], omxL[N];

void dfs1(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs1(v, u);
        imxR[u] = max(imxR[u], imxR[v]);
        imxL[u] = max(imxL[u], imxL[v]);
    }
    if (s[u] == '(')
        imxR[u]--, imxL[u]++;
    else
        imxL[u]--, imxR[u]++;
    imxR[u] = max(imxR[u], 0);
    imxL[u] = max(imxL[u], 0);
}

void dfs2(int u, int fa) {
    int mxR = 0, mxL = 0;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        omxR[v] = omxR[u], omxL[v] = omxL[u];
        omxR[v] = max(omxR[v], mxR);
        omxL[v] = max(omxL[v], mxL);
        mxR     = max(mxR, imxR[v]);
        mxL     = max(mxL, imxL[v]);
    }
    reverse(g[u].begin(), g[u].end());
    mxR = 0, mxL = 0;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        omxR[v] = max(omxR[v], mxR);
        omxL[v] = max(omxL[v], mxL);
        mxR     = max(mxR, imxR[v]);
        mxL     = max(mxL, imxL[v]);
    }
    reverse(g[u].begin(), g[u].end());
    for (int v : g[u]) {
        if (v == fa)
            continue;
        if (s[u] == '(')
            omxR[v]--, omxL[v]++;
        else
            omxL[v]--, omxR[v]++;
        omxR[v] = max(omxR[v], 0);
        omxL[v] = max(omxL[v], 0);
        dfs2(v, u);
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 2, p; i <= n; ++i)
        scanf("%d", &p), g[p].push_back(i);
    for (int i = 1; i <= n; ++i)
        scanf(" %c", &s[i]);
}

void process() {
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(imxL[i], omxR[i]));
        ans = max(ans, min(omxL[i], imxR[i]));
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
