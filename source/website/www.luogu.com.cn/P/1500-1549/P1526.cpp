#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double    db;

const int inf  = 0x3f3f3f3f;
const int maxN = 105;

int            m, n, k;
pair<int, int> tow[maxN], tar[maxN];
bitset<maxN>   canHit[maxN];

bitset<maxN> graph[maxN], vis;
int          nxt[maxN][maxN];
int          mn[maxN];
int          mat[maxN];
int          ans;

int sqr(int x) { return x * x; }

bool doMatch(int seg) {
    for (int i = 0; i < n; i++) {
        if (!graph[seg][i] || vis[i]) {
            continue;
        }
        vis[i] = true;
        if (mat[i] == -1 || doMatch(mat[i])) {
            mat[i] = seg;
            return true;
        }
    }
    return false;
}

void doDfs(int pos, int segCnt) {
    if (ans <= segCnt + mn[pos]) {
        return;
    }

    if (pos == m) {
        ans = segCnt;
        return;
    }

    int bakMat[maxN];
    copy(mat, mat + n, bakMat);

    for (int nxtPos = m; nxtPos > pos; nxtPos--) {
        for (int i = 0; i < n; i++) {
            if (canHit[i][pos] && nxt[i][pos] >= nxtPos) {
                graph[segCnt][i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }

        if (doMatch(segCnt)) {
            doDfs(nxtPos, segCnt + 1);
        }

        for (int i = 0; i < n; i++) {
            if (canHit[i][pos] && nxt[i][pos] >= nxtPos) {
                graph[segCnt][i] = false;
            }
        }

        copy(bakMat, bakMat + n, mat);
    }
}

int main() {
    scanf("%d%d%d", &m, &n, &k);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &tow[i].first, &tow[i].second);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &tar[i].first, &tar[i].second);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            canHit[i][j] = sqr(tow[j].first - tar[i].first) + sqr(tow[j].second - tar[i].second) <= sqr(k);
        }
    }

    for (int i = 0; i < n; i++) {
        fill(nxt[i], nxt[i] + m + 1, -1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (canHit[i][j]) {
                nxt[i][j] = max(j + 1, nxt[i][j + 1]);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        mn[i] = inf;
    }

    mn[m] = 0;

    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (canHit[i][j]) {
                mn[j] = min(mn[j], mn[nxt[i][j]] + 1);
            }
        }
    }

    fill(mat, mat + n, -1);

    ans = min(n, m);
    doDfs(0, 0);

    printf("%d\n", ans);

    return 0;
}
