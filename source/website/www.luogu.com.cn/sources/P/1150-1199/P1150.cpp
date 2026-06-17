#include <bits/stdc++.h>
using namespace std;

int n, k;

void input() {
    scanf("%d%d", &n, &k);
}

void process() {
    int ans = n + (n - 1) / (k - 1);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
