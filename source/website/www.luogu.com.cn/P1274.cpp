#include <bits/stdc++.h>
using namespace std;

int  a[16];
bool used[17];
int  fixPos;
bool firstOut = true;

bool chk(int r0, int c0, int r1, int c1, int r2, int c2, int r3, int c3) { return a[r0 * 4 + c0] + a[r1 * 4 + c1] + a[r2 * 4 + c2] + a[r3 * 4 + c3] == 34; }

bool checkComplete(int pos) {
    int r = pos / 4, c = pos % 4;
    if (c == 3 && !chk(r, 0, r, 1, r, 2, r, 3))
        return false;
    if (r == 3 && !chk(0, c, 1, c, 2, c, 3, c))
        return false;
    if (pos == 5 && !chk(0, 0, 0, 1, 1, 0, 1, 1))
        return false;
    if (pos == 7 && !chk(0, 2, 0, 3, 1, 2, 1, 3))
        return false;
    if (pos == 10 && !chk(1, 1, 1, 2, 2, 1, 2, 2))
        return false;
    if (pos == 12 && !chk(0, 3, 1, 2, 2, 1, 3, 0))
        return false;
    if (pos == 13 && !chk(2, 0, 2, 1, 3, 0, 3, 1))
        return false;
    if (pos == 15 && !chk(2, 2, 2, 3, 3, 2, 3, 3))
        return false;
    if (pos == 15 && !chk(0, 0, 0, 3, 3, 0, 3, 3))
        return false;
    if (pos == 15 && !chk(0, 0, 1, 1, 2, 2, 3, 3))
        return false;
    return true;
}

void output() {
    if (!firstOut)
        printf("\n");
    firstOut = false;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++)
            printf("%d ", a[r * 4 + c]);
        printf("\n");
    }
}

void dfs(int pos) {
    if (pos == 16) {
        output();
        return;
    }
    if (pos == fixPos) {
        if (checkComplete(pos))
            dfs(pos + 1);
        return;
    }
    for (int v = 2; v <= 16; v++) {
        if (!used[v]) {
            a[pos]  = v;
            used[v] = true;
            if (checkComplete(pos))
                dfs(pos + 1);
            used[v] = false;
        }
    }
}

int main() {
    int r, c;
    scanf("%d%d", &r, &c);
    fixPos    = (r - 1) * 4 + (c - 1);
    a[fixPos] = 1;
    used[1]   = true;
    dfs(0);
    return 0;
}
