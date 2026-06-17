#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;

int n, m, a[MAXN], que[MAXN], head, tail;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    head = 1, tail = 0;
    for (int i = 1; i <= n; ++i) {
        if (head <= tail)
            printf("%d\n", a[que[head]]);
        else
            printf("0\n");
        while (head <= tail && que[head] <= i - m)
            ++head;
        while (head <= tail && a[que[tail]] >= a[i])
            --tail;
        que[++tail] = i;
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
