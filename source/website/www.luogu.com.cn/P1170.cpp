#include <bits/stdc++.h>
using namespace std;

int n, ax, ay, bx, by;

void input() { scanf("%d", &n); }

void process() {
    while (n--) {
        scanf("%d%d%d%d", &ax, &ay, &bx, &by);
        int dx = abs(ax - bx);
        int dy = abs(ay - by);
        if (__gcd(dx, dy) == 1)
            printf("no\n");
        else
            printf("yes\n");
    }
}

int main() {
    input();
    process();
    return 0;
}
