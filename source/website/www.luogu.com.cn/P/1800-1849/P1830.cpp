#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int cnt[105][105], last[105][105];

void input() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 1; i <= x; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int r = x1; r <= x2; r++)
            for (int c = y1; c <= y2; c++) {
                cnt[r][c]++;
                last[r][c] = i;
            }
    }
}

void process() {
}

void output() {
    for (int i = 1; i <= y; i++) {
        int px, py;
        scanf("%d%d", &px, &py);
        if (cnt[px][py] == 0)
            printf("N\n");
        else
            printf("Y %d %d\n", cnt[px][py], last[px][py]);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
