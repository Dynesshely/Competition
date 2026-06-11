#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt[1005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
}

void process() {}

void output() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < cnt[i]; j++)
            printf("%d ", i);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
