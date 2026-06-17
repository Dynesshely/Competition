#include <bits/stdc++.h>
using namespace std;

const int N = 505;
char      s[N];
int       n, bestLast[N][N];

int cmpNum(int l1, int r1, int l2, int r2) {
    while (l1 < r1 && s[l1] == '0')
        ++l1;
    while (l2 < r2 && s[l2] == '0')
        ++l2;
    int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
    if (len1 <= 0)
        len1 = 0;
    if (len2 <= 0)
        len2 = 0;
    if (len1 != len2)
        return len1 - len2;
    for (int i = 0; i < len1; ++i)
        if (s[l1 + i] != s[l2 + i])
            return s[l1 + i] - s[l2 + i];
    return 0;
}

bool lessNum(int l1, int r1, int l2, int r2) { return cmpNum(l1, r1, l2, r2) < 0; }

void input() { scanf("%s", s + 1); }

void process() {
    n = strlen(s + 1);
    memset(bestLast, -1, sizeof(bestLast));
    for (int i = n; i >= 1; --i)
        for (int j = i; j <= n; ++j) {
            if (j == n) {
                bestLast[i][j] = i;
                continue;
            }
            int best = -1;
            for (int k = j + 1; k <= n; ++k) {
                if (bestLast[j + 1][k] == -1)
                    continue;
                if (!lessNum(i, j, j + 1, k))
                    continue;
                int cur = bestLast[j + 1][k];
                if (best == -1 || lessNum(cur, n, best, n))
                    best = cur;
            }
            bestLast[i][j] = best;
        }
    int bestFE = -1, bestLS = -1;
    for (int j = 1; j <= n; ++j) {
        if (bestLast[1][j] == -1)
            continue;
        int ls = bestLast[1][j];
        if (bestLS == -1 || lessNum(ls, n, bestLS, n) || (cmpNum(ls, n, bestLS, n) == 0 && cmpNum(1, j, 1, bestFE) > 0))
            bestLS = ls, bestFE = j;
    }
    int ls = bestLS;
    int prefLast[N][N];
    memset(prefLast, -1, sizeof(prefLast));
    for (int i = ls - 1; i >= 1; --i)
        for (int j = i; j <= ls - 1; ++j) {
            if (j == ls - 1) {
                if (lessNum(i, j, ls, n))
                    prefLast[i][j] = i;
                continue;
            }
            int best = -1;
            for (int k = j + 1; k <= ls - 1; ++k) {
                if (prefLast[j + 1][k] == -1)
                    continue;
                if (!lessNum(i, j, j + 1, k))
                    continue;
                int cur = prefLast[j + 1][k];
                if (best == -1 || lessNum(cur, n, cur, n))
                    best = cur;
            }
            if (best != -1)
                prefLast[i][j] = best;
        }
    for (int i = 1; i < ls;) {
        int best = -1;
        for (int j = i; j < ls; ++j) {
            bool ok = false;
            if (j == ls - 1)
                ok = lessNum(i, j, ls, n);
            else if (prefLast[j + 1][j + 1] != -1 || prefLast[j + 1][j + 2] != -1) {
                for (int k = j + 1; k < ls; ++k)
                    if (prefLast[j + 1][k] != -1 && lessNum(i, j, j + 1, k)) {
                        ok = true;
                        break;
                    }
            }
            if (ok && (best == -1 || cmpNum(i, j, i, best) > 0))
                best = j;
        }
        for (int k = i; k <= best; ++k)
            putchar(s[k]);
        i = best + 1;
        if (i < ls)
            putchar(',');
    }
    if (ls > 1)
        putchar(',');
    for (int i = ls; i <= n; ++i)
        putchar(s[i]);
    putchar('\n');
}

int main() {
    input();
    process();
    return 0;
}
