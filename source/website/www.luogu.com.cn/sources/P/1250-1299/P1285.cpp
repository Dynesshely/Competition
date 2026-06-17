#include <bits/stdc++.h>
using namespace std;

int         n;
bool        kn[105][105];
bool        cf[105][105];
int         cl[105];
bool        vd[105];
vector<int> comp[105];
int         cCnt;
int         cnt0[105], cnt1[105];

bool dfs(int u, int c, int cid) {
    vd[u] = true;
    cl[u] = c;
    comp[cid].push_back(u);
    if (c == 0)
        cnt0[cid]++;
    else
        cnt1[cid]++;
    for (int v = 1; v <= n; v++) {
        if (cf[u][v]) {
            if (!vd[v]) {
                if (!dfs(v, c ^ 1, cid))
                    return false;
            } else if (cl[v] == cl[u]) {
                return false;
            }
        }
    }
    return true;
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        while (scanf("%d", &x) && x)
            kn[i][x] = true;
    }
}

void process() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && !(kn[i][j] && kn[j][i]))
                cf[i][j] = true;
    for (int i = 1; i <= n; i++) {
        if (!vd[i]) {
            if (!dfs(i, 0, cCnt)) {
                printf("No solution\n");
                return;
            }
            cCnt++;
        }
    }
    vector<bool>        dp(n + 1, false);
    vector<vector<int>> choose(cCnt, vector<int>(n + 1, -1));
    dp[0] = true;
    for (int idx = 0; idx < cCnt; idx++) {
        int          a = cnt0[idx], b = cnt1[idx];
        vector<bool> ndp(n + 1, false);
        for (int s = 0; s <= n; s++) {
            if (dp[s]) {
                if (s + a <= n && !ndp[s + a]) {
                    ndp[s + a]         = true;
                    choose[idx][s + a] = 0;
                }
                if (s + b <= n && !ndp[s + b]) {
                    ndp[s + b]         = true;
                    choose[idx][s + b] = 1;
                }
            }
        }
        dp = ndp;
    }
    int bestS = -1, bestDiff = n + 1;
    for (int s = 1; s <= n - 1; s++) {
        if (dp[s] && abs(s - (n - s)) < bestDiff) {
            bestDiff = abs(s - (n - s));
            bestS    = s;
        }
    }
    if (bestS == -1) {
        printf("No solution\n");
        return;
    }
    vector<int> option(cCnt, -1);
    int         cur = bestS;
    for (int idx = cCnt - 1; idx >= 0; idx--) {
        option[idx] = choose[idx][cur];
        if (option[idx] == 0)
            cur -= cnt0[idx];
        else
            cur -= cnt1[idx];
    }
    vector<int> g1, g2;
    for (int idx = 0; idx < cCnt; idx++) {
        for (int v : comp[idx]) {
            if (option[idx] == 0) {
                if (cl[v] == 0)
                    g1.push_back(v);
                else
                    g2.push_back(v);
            } else {
                if (cl[v] == 1)
                    g1.push_back(v);
                else
                    g2.push_back(v);
            }
        }
    }
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    if (g1.size() < g2.size())
        swap(g1, g2);
    printf("%d", (int)g1.size());
    for (int v : g1)
        printf(" %d", v);
    printf("\n");
    printf("%d", (int)g2.size());
    for (int v : g2)
        printf(" %d", v);
    printf("\n");
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
