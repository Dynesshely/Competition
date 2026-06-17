#include <bits/stdc++.h>
using namespace std;

int                    n, m;
vector<pair<int, int>> cur;
vector<pair<int, int>> rowRes;
int shapes[4][5][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}}, {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 2}}, {{0, 1}, {1, 1}, {2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 0}}};

void rowDfs(int col, int rowR, int rowR1, int rowR2, int cnt) {
    if (col + 2 >= m) {
        rowRes.push_back({rowR1 | (rowR2 << m), cnt});
        return;
    }
    rowDfs(col + 1, rowR, rowR1, rowR2, cnt);
    for (int k = 0; k < 4; k++) {
        bool ok = true;
        int  nR = rowR, nR1 = rowR1, nR2 = rowR2;
        for (int q = 0; q < 5; q++) {
            int dr  = shapes[k][q][0];
            int dc  = shapes[k][q][1];
            int bit = col + dc;
            if (bit >= m) {
                ok = false;
                break;
            }
            if (dr == 0) {
                if (nR & (1 << bit)) {
                    ok = false;
                    break;
                }
                nR |= (1 << bit);
            } else if (dr == 1) {
                if (nR1 & (1 << bit)) {
                    ok = false;
                    break;
                }
                nR1 |= (1 << bit);
            } else {
                if (nR2 & (1 << bit)) {
                    ok = false;
                    break;
                }
                nR2 |= (1 << bit);
            }
        }
        if (!ok)
            continue;
        rowDfs(col + 1, nR, nR1, nR2, cnt + 1);
    }
}

int solve() {
    cur.clear();
    cur.push_back({0, 0});
    for (int r = 0; r + 2 < n; r++) {
        vector<pair<int, int>> nxt;
        for (auto &pr : cur) {
            int inM   = pr.first;
            int tot   = pr.second;
            int rowR  = inM & ((1 << m) - 1);
            int rowR1 = (inM >> m) & ((1 << m) - 1);
            rowRes.clear();
            rowDfs(0, rowR, rowR1, 0, 0);
            for (auto &res : rowRes) {
                int outM = res.first;
                int ext  = res.second;
                nxt.push_back({outM, tot + ext});
            }
        }
        sort(nxt.begin(), nxt.end());
        cur.clear();
        for (size_t i = 0; i < nxt.size();) {
            int    mask = nxt[i].first;
            int    best = nxt[i].second;
            size_t j    = i + 1;
            while (j < nxt.size() && nxt[j].first == mask) {
                if (nxt[j].second > best)
                    best = nxt[j].second;
                j++;
            }
            cur.push_back({mask, best});
            i = j;
        }
    }
    int ans = 0;
    for (auto &pr : cur)
        if (pr.second > ans)
            ans = pr.second;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    if (n < 3 || m < 3) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", solve());
    return 0;
}
