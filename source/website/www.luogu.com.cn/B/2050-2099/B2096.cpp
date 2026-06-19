#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100005;

int n, cnt[MAXV], maxV;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        if (x > maxV)
            maxV = x;
    }
}

void process() {
    for (int i = 0; i <= maxV; i++)
        printf("%d\n", cnt[i]);
}

int main() {
    input();
    process();
    return 0;
}
