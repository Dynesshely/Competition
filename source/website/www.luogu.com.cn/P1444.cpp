#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int   n;
Point p[15];
int   rightIdx[15], paired[15];
int   ans;

bool hasCycle() {
    for (int i = 0; i < n; i++) {
        int via[15] = {0};
        int cur     = i;
        while (true) {
            if (rightIdx[cur] == -1)
                break;
            cur = paired[rightIdx[cur]];
            if (via[cur])
                return true;
            via[cur] = 1;
        }
    }
    return false;
}

void dfs(int cnt) {
    if (cnt == n) {
        if (hasCycle())
            ans++;
        return;
    }
    int first = -1;
    for (int i = 0; i < n; i++)
        if (paired[i] == -1) {
            first = i;
            break;
        }
    for (int j = first + 1; j < n; j++)
        if (paired[j] == -1) {
            paired[first] = j;
            paired[j]     = first;
            dfs(cnt + 2);
            paired[first] = -1;
            paired[j]     = -1;
        }
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

void process() {
    sort(p, p + n, [](const Point &a, const Point &b) {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    });
    for (int i = 0; i < n; i++) {
        rightIdx[i] = -1;
        for (int j = i + 1; j < n; j++)
            if (p[j].y == p[i].y) {
                rightIdx[i] = j;
                break;
            }
    }
    memset(paired, -1, sizeof(paired));
    ans = 0;
    dfs(0);
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
