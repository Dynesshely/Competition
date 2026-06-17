#include <bits/stdc++.h>
using namespace std;

struct Stu {
    char name[25];
    int  y, m, d, idx;
};

Stu a[105];
int n;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", a[i].name, &a[i].y, &a[i].m, &a[i].d);
        a[i].idx = i;
    }
}

void process() {
    sort(a, a + n, [](const Stu &x, const Stu &y) {
        if (x.y != y.y)
            return x.y < y.y;
        if (x.m != y.m)
            return x.m < y.m;
        if (x.d != y.d)
            return x.d < y.d;
        return x.idx > y.idx;
    });
}

void output() {
    for (int i = 0; i < n; ++i)
        printf("%s\n", a[i].name);
}

int main() {
    input();
    process();
    output();
    return 0;
}
