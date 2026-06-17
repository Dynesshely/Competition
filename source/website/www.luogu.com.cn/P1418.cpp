#include <bits/stdc++.h>
using namespace std;

int n, m;
int r[110], c[110];
int remRow[110], remCol[110];
int ans[110][110];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &r[i]);
        remRow[i] = r[i];
    }
    for (int j = 1; j <= m; ++j) {
        scanf("%d", &c[j]);
        remCol[j] = c[j];
    }
}

void process() {
    for (int i = 1; i <= n; ++i) {
        vector<int> future;
        for (int p = i + 1; p <= n; ++p)
            if (remRow[p] > 0)
                future.push_back(remRow[p]);
        sort(future.begin(), future.end(), greater<int>());
        int         fsz = (int)future.size();
        vector<int> pref(fsz + 1, 0);
        for (int k = 1; k <= fsz; ++k)
            pref[k] = pref[k - 1] + future[k - 1];
        for (int j = 1; j <= m; ++j) {
            int ok = 1;
            if (remRow[i] <= m - j) {
                if (i < n) {
                    for (int k = 1; k <= fsz && ok; ++k) {
                        int rhs = 0;
                        for (int q = 1; q <= m; ++q)
                            rhs += min(k, remCol[q]);
                        if (pref[k] > rhs)
                            ok = 0;
                    }
                    for (int k = 1; k <= fsz + 1 && ok; ++k) {
                        int rowSum = remRow[i] + pref[k - 1];
                        int colCap = 0;
                        for (int q = 1; q <= j; ++q)
                            colCap += min(k - 1, remCol[q]);
                        for (int q = j + 1; q <= m; ++q)
                            colCap += min(k, remCol[q]);
                        if (rowSum > colCap)
                            ok = 0;
                    }
                } else {
                    int colCap = 0;
                    for (int q = j + 1; q <= m; ++q)
                        colCap += min(1, remCol[q]);
                    if (remRow[i] > colCap)
                        ok = 0;
                }
            } else
                ok = 0;
            if (ok)
                ans[i][j] = 0;
            else {
                ans[i][j] = 1;
                --remRow[i];
                --remCol[j];
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d", ans[i][j]);
        putchar('\n');
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
