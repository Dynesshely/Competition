#include <bits/stdc++.h>
using namespace std;

int         n, a[1005], minSuf[1005], col[1005];
vector<int> g[1005];
int         s1[1005], s2[1005], top1, top2;
char        ans[2005];
int         ansLen;

bool dfs(int u, int c) {
    col[u] = c;
    for (int v : g[u])
        if (col[v] == -1) {
            if (!dfs(v, c ^ 1))
                return false;
        } else if (col[v] == c)
            return false;
    return true;
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    minSuf[n + 1] = n + 1;
    for (int i = n; i >= 1; --i)
        minSuf[i] = min(minSuf[i + 1], a[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[i] < a[j] && minSuf[j + 1] < a[i]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; ++i)
        if (col[i] == -1)
            if (!dfs(i, 0)) {
                printf("0\n");
                return;
            }
    top1 = top2 = 0;
    ansLen      = 0;
    int cur = 1, pos = 1;
    while (cur <= n) {
        if (top1 && s1[top1] == cur) {
            ans[ansLen++] = 'b';
            --top1;
            ++cur;
        } else if (pos <= n && col[pos] == 0 && (!top1 || a[pos] < s1[top1])) {
            ans[ansLen++] = 'a';
            s1[++top1]    = a[pos];
            ++pos;
        } else if (top2 && s2[top2] == cur) {
            ans[ansLen++] = 'd';
            --top2;
            ++cur;
        } else if (pos <= n && col[pos] == 1 && (!top2 || a[pos] < s2[top2])) {
            ans[ansLen++] = 'c';
            s2[++top2]    = a[pos];
            ++pos;
        } else
            break;
    }
    if (cur <= n) {
        printf("0\n");
        return;
    }
}

void output() {
    for (int i = 0; i < ansLen; ++i) {
        if (i)
            printf(" ");
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
