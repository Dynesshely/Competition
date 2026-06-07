#include <bits/stdc++.h>
using namespace std;

int  n, m;
char g[1005][1005];
int  ans;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);
}

void process() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j + 3 < m && g[i][j] == 'h' && g[i][j + 1] == 'e' && g[i][j + 2] == 'h' && g[i][j + 3] == 'e')
                ans++;
            if (j - 3 >= 0 && g[i][j] == 'h' && g[i][j - 1] == 'e' && g[i][j - 2] == 'h' && g[i][j - 3] == 'e')
                ans++;
            if (i + 3 < n && g[i][j] == 'h' && g[i + 1][j] == 'e' && g[i + 2][j] == 'h' && g[i + 3][j] == 'e')
                ans++;
            if (i - 3 >= 0 && g[i][j] == 'h' && g[i - 1][j] == 'e' && g[i - 2][j] == 'h' && g[i - 3][j] == 'e')
                ans++;
        }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
