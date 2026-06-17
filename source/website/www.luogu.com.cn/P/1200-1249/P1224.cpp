#include <bits/stdc++.h>
using namespace std;

int                 n, d, k;
vector<vector<int>> vec;

int dotMod(int a, int b) {
    int  res = 0;
    int *va = vec[a].data(), *vb = vec[b].data();
    for (int i = 0; i < d; i++)
        res = (res + va[i] * vb[i]) % k;
    return res;
}

void output(int p, int q) {
    if (p > q)
        swap(p, q);
    printf("%d %d\n", p + 1, q + 1);
}

void input() {
    scanf("%d%d%d", &n, &d, &k);
    vec.resize(n, vector<int>(d));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++) {
            scanf("%d", &vec[i][j]);
            vec[i][j] %= k;
        }
}

void process() {
    mt19937     rng(time(0));
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    int trials = k == 2 ? 15 : 10;

    for (int t = 0; t < trials; t++) {
        shuffle(perm.begin(), perm.end(), rng);

        if (k == 2) {
            vector<int> pref(d, 0);
            for (int idx = 0; idx < n; idx++) {
                int  i   = perm[idx];
                int *vi  = vec[i].data();
                int  dot = 0;
                for (int j = 0; j < d; j++)
                    dot ^= (vi[j] & pref[j]);
                if (dot != (idx & 1)) {
                    for (int jdx = 0; jdx < idx; jdx++) {
                        int j = perm[jdx];
                        if (dotMod(i, j) == 0) {
                            output(i, j);
                            return;
                        }
                    }
                }
                for (int j = 0; j < d; j++)
                    pref[j] ^= vi[j];
            }
        } else {
            vector<int> pref(d * d, 0);
            for (int idx = 0; idx < n; idx++) {
                int  i   = perm[idx];
                int *vi  = vec[i].data();
                int  sum = 0;
                for (int a = 0; a < d; a++) {
                    int  via     = vi[a];
                    int *prefRow = pref.data() + a * d;
                    for (int b = 0; b < d; b++) {
                        int prod = via * vi[b];
                        sum += prod * prefRow[b];
                        prefRow[b] = (prefRow[b] + prod) % 3;
                    }
                }
                if (sum % 3 != idx % 3) {
                    for (int jdx = 0; jdx < idx; jdx++) {
                        int j = perm[jdx];
                        if (dotMod(i, j) == 0) {
                            output(i, j);
                            return;
                        }
                    }
                }
            }
        }
    }
    printf("-1 -1\n");
}

int main() {
    input();
    process();
    return 0;
}
