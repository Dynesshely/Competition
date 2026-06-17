#include <bits/stdc++.h>
using namespace std;

const int BASE = 1000000000;

struct BigInt {
    vector<int> d;

    BigInt() {}
    BigInt(int x) { d.push_back(x); }

    bool operator<(const BigInt &o) const {
        if (d.size() != o.d.size())
            return d.size() < o.d.size();
        for (int i = d.size() - 1; i >= 0; i--)
            if (d[i] != o.d[i])
                return d[i] < o.d[i];
        return false;
    }

    BigInt mul(const BigInt &o) const {
        BigInt res;
        res.d.assign(d.size() + o.d.size(), 0);
        for (int i = 0; i < (int)d.size(); i++) {
            long long carry = 0;
            for (int j = 0; j < (int)o.d.size(); j++) {
                carry += (long long)d[i] * o.d[j] + res.d[i + j];
                res.d[i + j] = carry % BASE;
                carry /= BASE;
            }
            int idx = i + (int)o.d.size();
            while (carry) {
                if (idx >= (int)res.d.size())
                    res.d.push_back(0);
                carry += res.d[idx];
                res.d[idx] = carry % BASE;
                carry /= BASE;
                idx++;
            }
        }
        while ((int)res.d.size() > 1 && res.d.back() == 0)
            res.d.pop_back();
        return res;
    }

    BigInt mul(int x) const {
        BigInt    res;
        long long carry = 0;
        for (int v : d) {
            carry += (long long)v * x;
            res.d.push_back(carry % BASE);
            carry /= BASE;
        }
        while (carry) {
            res.d.push_back(carry % BASE);
            carry /= BASE;
        }
        return res;
    }
};

int            n;
vector<int>    g[705];
int            sz[705];
vector<BigInt> dp[705];

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u].resize(2);
    dp[u][1] = BigInt(1);

    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u);

        BigInt bestV(0);
        for (int t = 1; t <= sz[v]; t++) {
            BigInt cur = dp[v][t].mul(t);
            if (bestV < cur)
                bestV = cur;
        }

        int            newSz = sz[u] + sz[v];
        vector<BigInt> ndp(newSz + 1);

        for (int s = 1; s <= sz[u]; s++) {
            if (dp[u][s].d.empty())
                continue;

            BigInt cutVal = dp[u][s].mul(bestV);
            if (ndp[s].d.empty() || ndp[s] < cutVal)
                ndp[s] = cutVal;

            for (int t = 1; t <= sz[v]; t++) {
                if (dp[v][t].d.empty())
                    continue;
                BigInt keepVal = dp[u][s].mul(dp[v][t]);
                if (ndp[s + t].d.empty() || ndp[s + t] < keepVal)
                    ndp[s + t] = keepVal;
            }
        }

        sz[u] = newSz;
        dp[u] = move(ndp);
    }
}

void output() {
    BigInt ans(0);
    for (int s = 1; s <= sz[1]; s++) {
        BigInt cur = dp[1][s].mul(s);
        if (ans < cur)
            ans = cur;
    }
    printf("%d", ans.d.back());
    for (int i = (int)ans.d.size() - 2; i >= 0; i--)
        printf("%09d", ans.d[i]);
    printf("\n");
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    output();
    return 0;
}
