#include <bits/stdc++.h>
using namespace std;

char pre[100], post[100];
int  n;

void input() {
    scanf("%s%s", pre, post);
    n = strlen(pre);
}

long long dfs(int l1, int r1, int l2, int r2) {
    if (l1 >= r1)
        return 1;
    char leftRoot = pre[l1 + 1];
    int  pos      = l2;
    while (post[pos] != leftRoot)
        pos++;
    int       leftSize  = pos - l2 + 1;
    int       rightSize = r1 - l1 - leftSize;
    long long res       = 1;
    if (leftSize)
        res *= dfs(l1 + 1, l1 + leftSize, l2, pos);
    if (rightSize)
        res *= dfs(l1 + leftSize + 1, r1, l2 + leftSize, r2 - 1);
    if (!leftSize || !rightSize)
        res *= 2;
    return res;
}

void process() {}

void output() { printf("%lld\n", dfs(0, n - 1, 0, n - 1)); }

int main() {
    input();
    process();
    output();
    return 0;
}
