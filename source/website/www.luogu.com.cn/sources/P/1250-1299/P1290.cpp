#include <bits/stdc++.h>
using namespace std;

int c;

bool dfs(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return false;
    if (a % b == 0)
        return true;
    if (a >= 2 * b)
        return true;
    return !dfs(b, a % b);
}

void input() { scanf("%d", &c); }

void process() {
    for (int i = 0; i < c; i++) {
        int m, n;
        scanf("%d%d", &m, &n);
        if (dfs(m, n))
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
