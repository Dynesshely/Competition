#include <bits/stdc++.h>
using namespace std;

int n, r;
int chosen[25];

void dfs(int start, int depth) {
    if (depth == r) {
        for (int i = 0; i < r; i++)
            printf("%3d", chosen[i]);
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++) {
        chosen[depth] = i;
        dfs(i + 1, depth + 1);
    }
}

void input() { scanf("%d%d", &n, &r); }

void process() { dfs(1, 0); }

void output() {}

int main() {
    input();
    process();
    return 0;
}
