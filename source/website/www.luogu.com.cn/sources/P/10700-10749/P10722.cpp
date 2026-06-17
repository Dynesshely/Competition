#include <cstdio>
#include <cstring>
#include <stdio.h>

#define DEBUG
#undef DEBUG

const int MAXN = 100000 + 5;

int n, q, *op;

int parent[MAXN], sons[MAXN * 2], reversedTime[MAXN];
int color[MAXN]; // 0 -> white, 1 -> black

bool exists(int id) { return parent[id] != -1; }

void init() {
    memset(parent, -1, sizeof(parent));
    memset(sons, -1, sizeof(sons));
    memset(reversedTime, 0, sizeof(reversedTime));
    parent[1] = 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 1, id; i <= n - 1; ++i) {
        scanf("%d", &id);
        parent[i + 1] = id;
        if (sons[id * 2] == -1) {
            sons[id * 2] = i + 1;
        } else {
            sons[id * 2 + 1] = i + 1;
        }
    }
    getchar();
    for (int i = 0; i < n; ++i) {
        char c = getchar();
        color[i + 1] = c - '0';
    }
    scanf("%d", &q);
    op = new int[q + 1];
    for (int i = 0, tmp; i < q; ++i) {
        scanf("%d", &tmp);
        op[i] = tmp;
    }

#ifdef DEBUG
    printf("\n");
    printf("[DEBUG] n & q : | n -> %d | q -> %d |\n", n, q);
    printf("[DEBUG] parent: | ");
    for (int i = 1; i <= n; ++i) {
        printf("%d -> %d | ", i, parent[i]);
    }
    printf("\n");
    printf("[DEBUG] color:  ");
    for (int i = 1; i <= n; ++i) {
        printf("%d", color[i]);
    }
    printf("\n");
    printf("[DEBUG] ops:    ");
    for (int i = 0; i < q; ++i) {
        printf("%d ", op[i]);
    }
    printf("\n");
#endif
}

void dfs(int i, int inherit) {
    reversedTime[i] += inherit;
    bool reversed = reversedTime[i] % 2 != 0;
    if (reversed)
        color[i] = 1 - color[i];
    reversedTime[i] = 0; // No need, but I like
    int ls = i * 2, rs = i * 2 + 1;
    if (sons[ls] != -1) {
        dfs(sons[ls], reversed ? 1 : 0);
        if (sons[rs] != -1)
            dfs(sons[rs], reversed ? 1 : 0);
    }
}

void process() {
    for (int i = 0; i < q; ++i) {
        reversedTime[op[i]]++;
    }
    dfs(1, 0);
}

void output() {
    for (int i = 1; i <= n; ++ i) {
        printf("%d", color[i]);
    }
    printf("\n");
}

int main() {
    init();

    input();

    process();

    output();

    return 0;
}
