#include <bits/stdc++.h>
using namespace std;

int  n, a[35][35];
bool via[35][35];
int  dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    via[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !via[nx][ny] && a[nx][ny] == 0)
            dfs(nx, ny);
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0 && !via[i][0])
            dfs(i, 0);
        if (a[i][n - 1] == 0 && !via[i][n - 1])
            dfs(i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (a[0][j] == 0 && !via[0][j])
            dfs(0, j);
        if (a[n - 1][j] == 0 && !via[n - 1][j])
            dfs(n - 1, j);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0 && !via[i][j])
                a[i][j] = 2;
}

void output() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
