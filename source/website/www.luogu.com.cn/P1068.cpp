#include <bits/stdc++.h>
using namespace std;

struct Stu { int id, score; } a[5005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].id, &a[i].score);
    sort(a, a + n, [](const Stu &x, const Stu &y) {
        if (x.score != y.score) return x.score > y.score;
        return x.id < y.id;
    });
    int need = m * 3 / 2, line = a[need - 1].score, cnt = 0;
    for (int i = 0; i < n && a[i].score >= line; ++i) ++cnt;
    printf("%d %d\n", line, cnt);
    for (int i = 0; i < cnt; ++i) printf("%d %d\n", a[i].id, a[i].score);
    return 0;
}
