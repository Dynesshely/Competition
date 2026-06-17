#include <bits/stdc++.h>
using namespace std;

int  n, grid[5][7], ans[5][3];
bool found;

void drop() {
    for (int x = 0; x < 5; x++) {
        int w = 0;
        for (int y = 0; y < 7; y++)
            if (grid[x][y])
                grid[x][w++] = grid[x][y];
        for (int y = w; y < 7; y++)
            grid[x][y] = 0;
    }
}

bool eliminate() {
    bool flag[5][7] = {{0}};
    bool any        = false;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 7; y++)
            if (grid[x][y] && grid[x][y] == grid[x + 1][y] && grid[x][y] == grid[x + 2][y])
                flag[x][y] = flag[x + 1][y] = flag[x + 2][y] = true;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++)
            if (grid[x][y] && grid[x][y] == grid[x][y + 1] && grid[x][y] == grid[x][y + 2])
                flag[x][y] = flag[x][y + 1] = flag[x][y + 2] = true;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 7; y++)
            if (flag[x][y])
                grid[x][y] = 0, any = true;
    return any;
}

void doMove(int x, int y, int dir) {
    swap(grid[x][y], grid[x + dir][y]);
    drop();
    while (eliminate())
        drop();
}

bool checkEmpty() {
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 7; y++)
            if (grid[x][y])
                return false;
    return true;
}

void dfs(int step) {
    if (found)
        return;
    if (step == n) {
        if (checkEmpty())
            found = true;
        return;
    }
    int cnt[11] = {0};
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 7; y++)
            if (grid[x][y])
                cnt[grid[x][y]]++;
    for (int i = 1; i <= 10; i++)
        if (cnt[i] && cnt[i] <= 2)
            return;
    int saved[5][7];
    memcpy(saved, grid, sizeof(grid));
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 7; y++) {
            if (!grid[x][y])
                continue;
            if (x < 4 && grid[x][y] != grid[x + 1][y]) {
                ans[step][0] = x;
                ans[step][1] = y;
                ans[step][2] = 1;
                doMove(x, y, 1);
                dfs(step + 1);
                if (found)
                    return;
                memcpy(grid, saved, sizeof(grid));
            }
            if (x > 0 && grid[x - 1][y] == 0) {
                ans[step][0] = x;
                ans[step][1] = y;
                ans[step][2] = -1;
                doMove(x, y, -1);
                dfs(step + 1);
                if (found)
                    return;
                memcpy(grid, saved, sizeof(grid));
            }
        }
    }
}

void input() {
    scanf("%d", &n);
    for (int x = 0; x < 5; x++) {
        int c, y = 0;
        while (scanf("%d", &c), c)
            grid[x][y++] = c;
    }
}

void process() { dfs(0); }

void output() {
    if (found)
        for (int i = 0; i < n; i++)
            printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    else
        printf("-1\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
