#include <bits/stdc++.h>
using namespace std;

int parent[30005], dist[30005], sz[30005];

int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]);
        dist[x] += dist[parent[x]];
        parent[x] = root;
    }
    return parent[x];
}

void merge(int i, int j) {
    int ri = find(i), rj = find(j);
    if (ri == rj)
        return;
    parent[ri] = rj;
    dist[ri]   = sz[rj];
    sz[rj] += sz[ri];
}

int query(int i, int j) {
    int ri = find(i), rj = find(j);
    if (ri != rj)
        return -1;
    return abs(dist[i] - dist[j]) - 1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= 30000; i++) {
        parent[i] = i;
        sz[i]     = 1;
    }
    while (t--) {
        char op[2];
        int  i, j;
        scanf("%s%d%d", op, &i, &j);
        if (op[0] == 'M')
            merge(i, j);
        else
            printf("%d\n", query(i, j));
    }
    return 0;
}
