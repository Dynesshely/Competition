#include <bits/stdc++.h>
using namespace std;

struct Node {
    int   t, cnt;
    Node *l, *r;
    Node(int _t, int _c)
        : t(_t)
        , cnt(_c)
        , l(nullptr)
        , r(nullptr) {}
};

Node *read() {
    int ti, cn;
    if (scanf("%d%d", &ti, &cn) != 2)
        return nullptr;
    Node *nd = new Node(ti, cn);
    if (cn == 0) {
        nd->l = read();
        nd->r = read();
    }
    return nd;
}

const int INF = 1e9;
int       budget;

vector<int> dfs(Node *nd) {
    if (nd->cnt > 0) {
        int         maxK = nd->cnt;
        vector<int> dp(maxK + 1, INF);
        dp[0]    = 0;
        int base = 2 * nd->t;
        for (int k = 1; k <= maxK; k++) {
            int val = base + 5 * k;
            if (val <= budget)
                dp[k] = val;
        }
        return dp;
    }
    vector<int> ldp  = dfs(nd->l);
    vector<int> rdp  = dfs(nd->r);
    int         maxK = (int)ldp.size() - 1 + (int)rdp.size() - 1;
    vector<int> dp(maxK + 1, INF);
    dp[0] = 0;
    for (int k1 = 0; k1 < (int)ldp.size(); k1++) {
        if (ldp[k1] >= INF)
            continue;
        for (int k2 = 0; k2 < (int)rdp.size(); k2++) {
            if (rdp[k2] >= INF)
                continue;
            int k   = k1 + k2;
            int val = ldp[k1] + rdp[k2];
            if (val < dp[k])
                dp[k] = val;
        }
    }
    int         add = 2 * nd->t;
    vector<int> res(maxK + 1, INF);
    res[0] = 0;
    for (int k = 1; k <= maxK; k++) {
        if (dp[k] < INF) {
            int val = dp[k] + add;
            if (val <= budget)
                res[k] = val;
        }
    }
    return res;
}

int main() {
    int policeTime;
    scanf("%d", &policeTime);
    budget     = policeTime - 1;
    Node *root = read();
    if (root == nullptr) {
        printf("0\n");
        return 0;
    }
    vector<int> dp  = dfs(root);
    int         ans = 0;
    for (int k = 0; k < (int)dp.size(); k++)
        if (dp[k] <= budget)
            ans = k;
    printf("%d\n", ans);
    return 0;
}
