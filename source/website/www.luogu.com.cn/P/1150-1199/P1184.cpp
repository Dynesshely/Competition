#include <bits/stdc++.h>
using namespace std;

int                   n, m, ans;
char                  buf[1005];
unordered_set<string> via;

void input() {
    scanf("%d%d", &n, &m);
    fgets(buf, sizeof(buf), stdin);
    for (int i = 0; i < n; i++) {
        fgets(buf, sizeof(buf), stdin);
        int len = strlen(buf);
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
            buf[--len] = 0;
        via.insert(buf);
    }
}

void process() {
    for (int i = 0; i < m; i++) {
        fgets(buf, sizeof(buf), stdin);
        int len = strlen(buf);
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
            buf[--len] = 0;
        if (via.count(buf))
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
