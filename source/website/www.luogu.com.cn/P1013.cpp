#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector tbl(n, vector<string>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char s[10];
            scanf("%s", s);
            tbl[i][j] = s;
        }
    vector<char> letters;
    for (int j = 1; j < n; ++j)
        letters.push_back(tbl[0][j][0]);
    int m = n - 1;
    vector<int> perm(m);
    iota(perm.begin(), perm.end(), 0);
    do {
        int val[256] = {};
        for (int i = 0; i < m; ++i)
            val[(int)letters[i]] = perm[i];
        int one_char = -1;
        for (int i = 0; i < m; ++i)
            if (perm[i] == 1) one_char = letters[i];
        if (one_char == -1) continue;
        int base = -1;
        bool ok = true;
        for (int i = 1; i < n && ok; ++i)
            for (int j = 1; j < n && ok; ++j) {
                int a = val[(int)tbl[i][0][0]];
                int b = val[(int)tbl[0][j][0]];
                int sum = a + b;
                const string &res = tbl[i][j];
                if (res.size() == 1) {
                    if (sum != val[(int)res[0]]) ok = false;
                } else if (res.size() == 2) {
                    if ((int)res[0] != one_char) ok = false;
                    int cb = sum - val[(int)res[1]];
                    if (cb <= a || cb <= b) ok = false;
                    if (base == -1) base = cb;
                    else if (base != cb) ok = false;
                } else ok = false;
            }
        if (ok && base > 0) {
            for (int i = 1; i < n && ok; ++i)
                for (int j = 1; j < n && ok; ++j)
                    if (tbl[i][j].size() == 1 && val[(int)tbl[i][j][0]] >= base)
                        ok = false;
            if (ok) {
                for (int k = 0; k < m; ++k)
                    printf("%c=%d ", letters[k], val[(int)letters[k]]);
                printf("\n%d\n", base);
                return 0;
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));
    printf("ERROR!\n");
    return 0;
}
