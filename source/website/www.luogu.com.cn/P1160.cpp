#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int       n, m, head;
int       l[MAXN], r[MAXN];
bool      via[MAXN];

void input() {
    scanf("%d", &n);
    head = 1;
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        if (p == 0) {
            l[i] = l[k];
            r[i] = k;
            if (l[k])
                r[l[k]] = i;
            l[k] = i;
            if (head == k)
                head = i;
        } else {
            l[i] = k;
            r[i] = r[k];
            if (r[k])
                l[r[k]] = i;
            r[k] = i;
        }
    }
}

void process() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        if (!via[x]) {
            via[x] = true;
            if (l[x])
                r[l[x]] = r[x];
            if (r[x])
                l[r[x]] = l[x];
            if (head == x)
                head = r[x];
        }
    }
}

void output() {
    for (int i = head; i; i = r[i])
        printf("%d ", i);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
