#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, op[40000], coef[40000], isVar1[40000], isVar2[40000], br1[40000], br2[40000], v1[40000], v2[40000];
ll curVal[20], bestVal1;
int first, choice[100], choiceCnt, bestChoice[100], bestCnt;
ll bestVal[20];
int curL, curR;
int flatOut[40000], flatOutLen;

ll wei[2010], val[2010], cap;
int tn, chosen[2010], treeStk[2010], treeTop;
ll dp1[2010][10010], dp2[2010][5010], dpTo[2010][10010];
vector<int> tree[2010];
int bestCntM[2010], bestChoiceM[2010][100];

void dfs(int t) {
    if (t < 0 || t > curR) {
        if (first)
            first = 0, bestCnt = choiceCnt, bestVal1 = curVal[1];
        else if (curVal[1] <= bestVal1)
            return;
        for (int i = 1; i <= choiceCnt; i++)
            bestChoice[i] = choice[i];
        for (int i = 1; i <= m; i++)
            bestVal[i] = curVal[i];
        bestCnt = choiceCnt, bestVal1 = curVal[1];
        return;
    }
    if (op[t] == 0) {
        ll add = coef[t] * (isVar2[t] ? curVal[v2[t]] : v2[t]);
        curVal[v1[t]] += add, dfs(t + 1), curVal[v1[t]] -= add;
    } else if (op[t] == 1)
        choice[++choiceCnt] = 1, dfs(br1[t]), --choiceCnt, choice[++choiceCnt] = 2, dfs(br2[t]), --choiceCnt;
    else {
        ll le = isVar1[t] ? curVal[v1[t]] : v1[t], ri = isVar2[t] ? curVal[v2[t]] : v2[t];
        dfs(le < ri ? br1[t] : br2[t]);
    }
}

bool canMerge(int t) {
    if (op[t] != 0)
        return true;
    if (coef[t] != -1)
        return true;
    if (isVar2[t] != 1)
        return true;
    if (v1[t] != m || v2[t] != m)
        return true;
    return false;
}

void addEdge(int u, int v) { tree[u].push_back(v); }

void doDp(int u) {
    int fir = 1, lv = 0;
    for (int i = 0, sz = tree[u].size(); i < sz; i++) {
        int v = tree[u][i];
        doDp(v);
        if (fir) {
            for (int j = wei[v]; j <= cap; j++)
                dp2[v][j] = dp1[v][j - wei[v]] + val[v], dpTo[v][j] = j;
            fir = 0;
        } else {
            for (int j = 0; j <= cap; j++)
                dp2[v][j] = dp2[lv][j], dpTo[v][j] = 0;
            for (int j = 0; j <= cap; j++)
                for (int k = 0; j + k + wei[v] <= cap; k++) {
                    ll nv = dp2[lv][j] + dp1[v][k] + val[v];
                    if (nv > dp2[v][j + k + wei[v]])
                        dp2[v][j + k + wei[v]] = nv, dpTo[v][j + k + wei[v]] = k + wei[v];
                }
        }
        lv = v;
    }
    if (!fir)
        for (int i = 0; i <= cap; i++)
            dp1[u][i] = dp2[lv][i];
}

void doWork(int u, ll lm) {
    chosen[u] = 1;
    int sz = tree[u].size();
    for (int i = sz - 1; i >= 0; i--) {
        int v = tree[u][i];
        if (dpTo[v][lm])
            doWork(v, dpTo[v][lm] - wei[v]), lm -= dpTo[v][lm];
    }
}

void doPrint46(int u, ll &lm) {
    if (chosen[u])
        printf("1\n"), lm -= wei[u];
    else {
        printf("2\n");
        return;
    }
    for (int i = 0, sz = tree[u].size(); i < sz; i++) {
        int v = tree[u][i];
        if (lm >= wei[v])
            doPrint46(v, lm);
    }
}

void doPrint910(int u, ll &lm) {
    if (chosen[u])
        printf("1\n"), lm -= wei[u];
    else {
        printf("2\n");
        return;
    }
    for (int i = 1; i <= bestCntM[u]; i++)
        printf("%d\n", bestChoiceM[u][i]);
    for (int i = 0, sz = tree[u].size(); i < sz; i++) {
        int v = tree[u][i];
        if (lm >= wei[v])
            doPrint910(v, lm);
    }
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char ch = getchar();
        while (ch != 'v' && ch != 's' && ch != 'i')
            ch = getchar();
        if (ch == 'v') {
            op[i] = 0, isVar1[i] = 1;
            scanf("%d", &v1[i]);
            ch = getchar();
            while (ch != '+' && ch != '-')
                ch = getchar();
            coef[i] = ch == '+' ? 1 : -1;
            ch      = getchar();
            while (ch != 'v' && ch != 'c')
                ch = getchar();
            isVar2[i] = ch == 'v' ? 1 : 0;
            scanf("%d", &v2[i]);
        } else if (ch == 's')
            op[i] = 1, scanf("%d%d", &br1[i], &br2[i]);
        else {
            op[i] = 2, ch = getchar();
            while (ch != 'v' && ch != 'c')
                ch = getchar();
            isVar1[i] = ch == 'v' ? 1 : 0;
            scanf("%d", &v1[i]);
            ch = getchar();
            while (ch != 'v' && ch != 'c')
                ch = getchar();
            isVar2[i] = ch == 'v' ? 1 : 0;
            scanf("%d", &v2[i]);
            scanf("%d%d", &br1[i], &br2[i]);
        }
    }
}

void solve13() {
    for (int i = 1; i <= n; i++) {
        curR = curL = i;
        while (curR < n && canMerge(curR))
            ++curR;
        first = 1, choiceCnt = bestCnt = 0;
        for (int j = 1; j <= m; j++)
            curVal[j] = bestVal[j];
        for (int j = 3; j <= m; j++)
            if (curVal[j] != 0) {
                printf("%d %d", i, j);
                return;
            }
        dfs(curL);
        for (int j = 1; j <= bestCnt; j++)
            flatOut[++flatOutLen] = bestChoice[j];
        i = curR;
    }
    for (int i = 1; i <= flatOutLen; i++)
        printf("%d\n", flatOut[i]);
}

void solve46() {
    cap = v2[1];
    for (int i = 2; i <= n; i++)
        if (isVar1[i] == 1) {
            ++tn, wei[tn] = v2[i + 3], val[tn] = v2[i + 4];
            treeStk[++treeTop] = tn;
            i = i + 4;
        } else {
            int bxh = treeStk[treeTop];
            --treeTop;
            if (treeTop)
                addEdge(treeStk[treeTop], bxh);
        }
    doDp(1), doWork(1, cap - wei[1]);
    ll lm = cap;
    doPrint46(1, lm);
}

void solve78() {
    cap = v2[1];
    for (int i = 2; i <= n; i++) {
        ++tn, wei[tn] = v2[i + 3];
        curL = i + 4, curR = br1[i + 1], first = 1;
        dfs(curL);
        val[tn]       = bestVal1;
        bestCntM[tn]  = bestCnt;
        for (int j = 1; j <= bestCnt; j++)
            bestChoiceM[tn][j] = bestChoice[j];
        i = curR - 1;
    }
    for (int i = 1; i <= tn; i++) {
        for (int j = 0; j <= cap; j++)
            dp1[i][j] = dp1[i - 1][j];
        for (int j = wei[i]; j <= cap; j++)
            dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - wei[i]] + val[i]);
    }
    ll lm = cap;
    for (int i = tn; i; i--)
        if (lm >= wei[i] && dp1[i - 1][lm - wei[i]] + val[i] > dp1[i - 1][lm])
            chosen[i] = 1, lm -= wei[i];
    for (int i = 1; i <= tn; i++)
        if (cap >= wei[i]) {
            if (chosen[i]) {
                printf("1\n");
                for (int j = 1; j <= bestCntM[i]; j++)
                    printf("%d\n", bestChoiceM[i][j]);
                cap -= wei[i];
            } else
                printf("2\n");
        }
}

void solve910() {
    cap = v2[1];
    for (int i = 2; i <= n; i++)
        if (isVar1[i] == 1) {
            ++tn, wei[tn] = v2[i + 3];
            curR = curL = i + 4, first = 1;
            while (curR < n && canMerge(curR))
                ++curR;
            dfs(curL);
            val[tn]       = bestVal1;
            bestCntM[tn]  = bestCnt;
            for (int j = 1; j <= bestCnt; j++)
                bestChoiceM[tn][j] = bestChoice[j];
            treeStk[++treeTop] = tn;
            i = curR;
        } else {
            int bxh = treeStk[treeTop];
            --treeTop;
            if (treeTop)
                addEdge(treeStk[treeTop], bxh);
        }
    doDp(1), doWork(1, cap - wei[1]);
    ll lm = cap;
    doPrint910(1, lm);
}

int main(int argc, char **argv) {
    int tid = 1;
    if (argc > 1)
        tid = atoi(argv[1]);
    char inName[20], outName[20];
    sprintf(inName, "train%d.in", tid);
    sprintf(outName, "train%d.out", tid);
    freopen(inName, "r", stdin);
    freopen(outName, "w", stdout);
    input();
    if (tid <= 3)
        solve13();
    else if (tid <= 6)
        solve46();
    else if (tid <= 8)
        solve78();
    else
        solve910();
    return 0;
}
