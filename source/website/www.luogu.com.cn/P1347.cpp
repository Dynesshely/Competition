#include <bits/stdc++.h>
using namespace std;

int         n, m;
vector<int> adj[26];
int         inDeg[26];
bool        edge[26][26];

int main() {
    scanf("%d%d", &n, &m);
    memset(inDeg, 0, sizeof(inDeg));
    memset(edge, 0, sizeof(edge));

    for (int i = 1; i <= m; i++) {
        char buf[4];
        scanf("%s", buf);
        int u = buf[0] - 'A';
        int v = buf[2] - 'A';

        if (!edge[u][v]) {
            edge[u][v] = true;
            adj[u].push_back(v);
            inDeg[v]++;
        }

        int tmpInDeg[26];
        memcpy(tmpInDeg, inDeg, sizeof(inDeg));

        queue<int> q;
        for (int j = 0; j < n; j++)
            if (tmpInDeg[j] == 0)
                q.push(j);

        vector<int> order;
        bool        unique = true;

        while (!q.empty()) {
            if (q.size() > 1)
                unique = false;
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for (int nxt : adj[cur])
                if (--tmpInDeg[nxt] == 0)
                    q.push(nxt);
        }

        if ((int)order.size() < n) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }

        if (unique) {
            printf("Sorted sequence determined after %d relations: ", i);
            for (int v : order)
                putchar('A' + v);
            printf(".\n");
            return 0;
        }
    }

    printf("Sorted sequence cannot be determined.\n");
    return 0;
}
