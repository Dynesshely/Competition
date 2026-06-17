#include <bits/stdc++.h>
using namespace std;

int  n, a[100005], to[100005];
bool via[100005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i)
        p[i] = {a[i], i};
    sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i)
        to[p[i].second] = i;
}

void output() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (via[i] || to[i] == i)
            continue;
        int len = 0, cur = i;
        while (!via[cur]) {
            via[cur] = true;
            cur      = to[cur];
            ++len;
        }
        ans += len - 1;
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
