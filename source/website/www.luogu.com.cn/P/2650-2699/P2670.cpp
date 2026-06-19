#include <bits/stdc++.h>
using namespace std;

int  n, m;
char g[105][105];
int  dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int  dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", g[i]);
}

void process() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == '?') {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == '*')
                        ++cnt;
                }
                g[i][j] = '0' + cnt;
            }
}

void output() {
    for (int i = 0; i < n; ++i)
        printf("%s\n", g[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
