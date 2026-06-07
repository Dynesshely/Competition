#include <bits/stdc++.h>
using namespace std;

int k, x, y;

void input() { scanf("%d%d%d", &k, &x, &y); }

void solve(int x0, int y0, int sx, int sy, int n) {
    if (n == 2) {
        if (sx == x0 && sy == y0)
            printf("%d %d 1\n", x0 + 1, y0 + 1);
        else if (sx == x0 && sy == y0 + 1)
            printf("%d %d 2\n", x0 + 1, y0);
        else if (sx == x0 + 1 && sy == y0)
            printf("%d %d 3\n", x0, y0 + 1);
        else
            printf("%d %d 4\n", x0, y0);
        return;
    }
    int half = n / 2;
    int midX = x0 + half - 1;
    int midY = y0 + half - 1;
    if (sx <= midX && sy <= midY) {
        printf("%d %d 1\n", midX + 1, midY + 1);
        solve(x0, y0, sx, sy, half);
        solve(x0, midY + 1, midX, midY + 1, half);
        solve(midX + 1, y0, midX + 1, midY, half);
        solve(midX + 1, midY + 1, midX + 1, midY + 1, half);
    } else if (sx <= midX && sy > midY) {
        printf("%d %d 2\n", midX + 1, midY);
        solve(x0, y0, midX, midY, half);
        solve(x0, midY + 1, sx, sy, half);
        solve(midX + 1, y0, midX + 1, midY, half);
        solve(midX + 1, midY + 1, midX + 1, midY + 1, half);
    } else if (sx > midX && sy <= midY) {
        printf("%d %d 3\n", midX, midY + 1);
        solve(x0, y0, midX, midY, half);
        solve(x0, midY + 1, midX, midY + 1, half);
        solve(midX + 1, y0, sx, sy, half);
        solve(midX + 1, midY + 1, midX + 1, midY + 1, half);
    } else {
        printf("%d %d 4\n", midX, midY);
        solve(x0, y0, midX, midY, half);
        solve(x0, midY + 1, midX, midY + 1, half);
        solve(midX + 1, y0, midX + 1, midY, half);
        solve(midX + 1, midY + 1, sx, sy, half);
    }
}

void process() { solve(1, 1, x, y, 1 << k); }

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
