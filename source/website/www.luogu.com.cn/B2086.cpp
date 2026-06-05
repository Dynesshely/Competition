#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void input() { scanf("%d%d%d", &a, &b, &c); }

void process() {
    int cnt = 0;
    for (int x = 0; x * a <= c; ++x) {
        if ((c - a * x) % b == 0) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
}

int main() {
    input();
    process();
    return 0;
}
