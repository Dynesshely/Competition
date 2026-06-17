#include <bits/stdc++.h>
using namespace std;

int            k, n, m;
int            a[105][105], b[105][105];
int            r[105];
vector<string> ca, cb;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
}

bool check() {
    ca.clear();
    cb.clear();
    for (int j = 0; j < m; j++) {
        string s;
        for (int i = 0; i < n; i++)
            s += '0' + (a[i][j] ^ r[i]);
        ca.push_back(s);
    }
    for (int j = 0; j < m; j++) {
        string s;
        for (int i = 0; i < n; i++)
            s += '0' + b[i][j];
        cb.push_back(s);
    }
    sort(ca.begin(), ca.end());
    sort(cb.begin(), cb.end());
    return ca == cb;
}

bool process() {
    for (int jA = 0; jA < m; jA++) {
        for (int i = 0; i < n; i++)
            r[i] = a[i][jA] ^ b[i][0];
        if (check())
            return true;
    }
    return false;
}

void output(bool ok) { puts(ok ? "YES" : "NO"); }

void solve() {
    input();
    output(process());
}

int main() {
    scanf("%d", &k);
    while (k--)
        solve();
    return 0;
}
