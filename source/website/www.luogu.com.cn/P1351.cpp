#include <bits/stdc++.h>
using namespace std;

int         n;
vector<int> adj[200005];
int         w[200005];
int         maxAns, sumAns;
const int   MOD = 10007;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
}

void process() {
    maxAns = 0;
    sumAns = 0;
    for (int u = 1; u <= n; u++) {
        if (adj[u].size() < 2)
            continue;
        int max1 = 0, max2 = 0;
        int sum = 0, sumSq = 0;
        for (int v : adj[u]) {
            int val = w[v];
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2)
                max2 = val;
            sum   = (sum + val) % MOD;
            sumSq = (sumSq + val * val) % MOD;
        }
        maxAns = max(maxAns, max1 * max2);
        sumAns = (sumAns + (sum * sum % MOD - sumSq + MOD)) % MOD;
    }
}

void output() { printf("%d %d\n", maxAns, sumAns); }

int main() {
    input();
    process();
    output();
    return 0;
}
