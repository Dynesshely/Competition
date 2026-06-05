#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int a[105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
}

void process() {
    cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == m)
            cnt++;
}

void output() { printf("%d\n", cnt); }

int main() {
    input();
    process();
    output();
    return 0;
}
