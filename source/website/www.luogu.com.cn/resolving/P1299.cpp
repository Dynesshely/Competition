#include <bits/stdc++.h>
using namespace std;

struct Point {
    int  x, y;
    bool operator<(const Point &o) const {
        if (x != o.x)
            return x < o.x;
        return y < o.y;
    }
};

struct Cut {
    int x1, y1, x2, y2;
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int  find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[a] = b;
    }
};

void input(vector<Cut> &cuts, int &n) {
    scanf("%d", &n);
    cuts.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &cuts[i].x1, &cuts[i].y1, &cuts[i].x2, &cuts[i].y2);
        if (cuts[i].x1 == cuts[i].x2) {
            if (cuts[i].y1 > cuts[i].y2)
                swap(cuts[i].y1, cuts[i].y2);
        } else {
            if (cuts[i].x1 > cuts[i].x2)
                swap(cuts[i].x1, cuts[i].x2);
        }
    }
}

void process(const vector<Cut> &cuts, int n, int &result) {
    set<Point> vertexSet;

    for (auto &c : cuts) {
        vertexSet.insert({c.x1, c.y1});
        vertexSet.insert({c.x2, c.y2});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto &a = cuts[i];
            auto &b = cuts[j];
            if (a.y1 == a.y2 && b.x1 == b.x2) {
                if (b.x1 >= a.x1 && b.x1 <= a.x2 && a.y1 >= b.y1 && a.y1 <= b.y2)
                    vertexSet.insert({b.x1, a.y1});
            } else if (a.x1 == a.x2 && b.y1 == b.y2) {
                if (a.x1 >= b.x1 && a.x1 <= b.x2 && b.y1 >= a.y1 && b.y1 <= a.y2)
                    vertexSet.insert({a.x1, b.y1});
            } else if (a.y1 == a.y2 && b.y1 == b.y2 && a.y1 == b.y1) {
                int l = max(a.x1, b.x1), r = min(a.x2, b.x2);
                if (l <= r) {
                    vertexSet.insert({l, a.y1});
                    vertexSet.insert({r, a.y1});
                }
            } else if (a.x1 == a.x2 && b.x1 == b.x2 && a.x1 == b.x1) {
                int l = max(a.y1, b.y1), r = min(a.y2, b.y2);
                if (l <= r) {
                    vertexSet.insert({a.x1, l});
                    vertexSet.insert({a.x1, r});
                }
            }
        }
    }

    vector<Point> verts(vertexSet.begin(), vertexSet.end());
    int           v = verts.size();

    map<Point, int> idxMap;
    for (int i = 0; i < v; i++)
        idxMap[verts[i]] = i;

    set<pair<int, int>> edgeSet;

    for (auto &c : cuts) {
        vector<int> ptsIdx;
        for (int k = 0; k < v; k++) {
            auto &p = verts[k];
            if (c.y1 == c.y2 && p.y == c.y1 && p.x >= c.x1 && p.x <= c.x2)
                ptsIdx.push_back(k);
            else if (c.x1 == c.x2 && p.x == c.x1 && p.y >= c.y1 && p.y <= c.y2)
                ptsIdx.push_back(k);
        }
        if (c.y1 == c.y2) {
            sort(ptsIdx.begin(), ptsIdx.end(), [&](int a, int b) { return verts[a].x < verts[b].x; });
        } else {
            sort(ptsIdx.begin(), ptsIdx.end(), [&](int a, int b) { return verts[a].y < verts[b].y; });
        }
        for (size_t k = 1; k < ptsIdx.size(); k++) {
            int a = ptsIdx[k - 1], b = ptsIdx[k];
            if (a > b)
                swap(a, b);
            edgeSet.insert({a, b});
        }
    }

    int e = edgeSet.size();

    DSU dsu(v);
    for (auto &edge : edgeSet)
        dsu.unite(edge.first, edge.second);

    int c = 0;
    for (int i = 0; i < v; i++)
        if (dsu.find(i) == i)
            c++;

    result = e - v + c;
}

void output(int result) { printf("%d\n", result); }

int main() {
    int         n;
    vector<Cut> cuts;
    input(cuts, n);
    int result = 0;
    process(cuts, n, result);
    output(result);
    return 0;
}
