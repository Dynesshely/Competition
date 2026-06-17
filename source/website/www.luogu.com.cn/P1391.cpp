#include <bits/stdc++.h>
using namespace std;

int n, ans, init[20][20];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &init[i][j]);
}

void process() {
    ans = -1;
    if (n == 1) {
        ans = 0;
        return;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int  row[20][20];
        bool ok      = true;
        int  changes = 0;
        for (int j = 0; j < n; j++) {
            row[0][j] = (mask >> j) & 1;
            if (row[0][j] < init[0][j]) {
                ok = false;
                break;
            }
            changes += (row[0][j] > init[0][j]);
        }
        if (!ok)
            continue;
        for (int j = 0; j < n; j++) {
            row[1][j] = (j > 0 ? row[0][j - 1] : 0) ^ (j < n - 1 ? row[0][j + 1] : 0);
            if (row[1][j] < init[1][j]) {
                ok = false;
                break;
            }
            changes += (row[1][j] > init[1][j]);
        }
        if (!ok)
            continue;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j] = row[i - 2][j] ^ (j > 0 ? row[i - 1][j - 1] : 0) ^ (j < n - 1 ? row[i - 1][j + 1] : 0);
                if (row[i][j] < init[i][j]) {
                    ok = false;
                    break;
                }
                changes += (row[i][j] > init[i][j]);
            }
            if (!ok)
                break;
        }
        if (!ok)
            continue;
        for (int j = 0; j < n; j++)
            if ((row[n - 2][j] ^ (j > 0 ? row[n - 1][j - 1] : 0) ^ (j < n - 1 ? row[n - 1][j + 1] : 0)) != 0) {
                ok = false;
                break;
            }
        if (!ok)
            continue;
        if (ans == -1 || changes < ans)
            ans = changes;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
