#include <bits/stdc++.h>
using namespace std;
int n, m, p, x, y, f[1010], sum = 0;
bool enemy[1010][1010];
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void combine(int a, int b) { f[a] = b; }
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &p, &x, &y);
        if (p == 0)
            combine(x, y);
        else
            enemy[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        queue<int> waiting;
        for (int j = 1; j <= n; ++j)
            if (enemy[i][j])
                waiting.push(j);
        while (true) {
            int a, b;
            if (!waiting.empty()) {
                a = waiting.front();
                waiting.pop();
            } else
                break;
            if (!waiting.empty()) {
                b = waiting.front();
                waiting.pop();
            } else
                break;
            combine(a, b);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (find(i) == i)
            sum++;
    printf("%d\n", sum);
    return 0;
}
