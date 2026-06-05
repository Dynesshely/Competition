#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 500005;

struct Edge {
    int to, w;
};

int          n, s;
vector<Edge> adj[MAXN];
ll           maxDist[MAXN], ans;
int          parent[MAXN];

void input() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i < n; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
}

void process() {
    vector<int> order;
    stack<int>  st;
    st.push(s);
    parent[s] = -1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        order.push_back(u);
        for (auto &e : adj[u])
            if (e.to != parent[u]) {
                parent[e.to] = u;
                st.push(e.to);
            }
    }
    for (int i = n - 1; i >= 0; i--) {
        int u    = order[i];
        ll  maxW = 0;
        for (auto &e : adj[u])
            if (e.to != parent[u])
                maxW = max(maxW, maxDist[e.to] + e.w);
        maxDist[u] = maxW;
        for (auto &e : adj[u])
            if (e.to != parent[u])
                ans += maxW - (maxDist[e.to] + e.w);
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
