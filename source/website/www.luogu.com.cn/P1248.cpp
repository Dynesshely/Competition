#include <bits/stdc++.h>
using namespace std;

struct Product {
    int id, a, b;
};

Product p[1005];
int     n;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].a);
        p[i].id = i + 1;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].b);
}

void process() {
    sort(p, p + n, [](const Product &x, const Product &y) {
        if (x.a <= x.b && y.a > y.b)
            return true;
        if (x.a > x.b && y.a <= y.b)
            return false;
        if (x.a <= x.b)
            return x.a < y.a;
        return x.b > y.b;
    });
}

void output() {
    int timeA = 0, timeB = 0;
    for (int i = 0; i < n; i++) {
        timeA += p[i].a;
        timeB = max(timeB, timeA) + p[i].b;
    }
    printf("%d\n", timeB);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i].id);
}

int main() {
    input();
    process();
    output();
    return 0;
}
