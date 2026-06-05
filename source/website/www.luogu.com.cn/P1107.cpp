#include <bits/stdc++.h>
using namespace std;

int                 n, h, delta;
vector<vector<int>> a;
int                 ans;

void input() {
    scanf("%d%d%d", &n, &h, &delta);
    a.assign(n, vector<int>(h + 1, 0));
    for (int i = 0; i < n; i++) {
        int ni;
        scanf("%d", &ni);
        while (ni--) {
            int x;
            scanf("%d", &x);
            a[i][x]++;
        }
    }
}

void process() {
    vector<int> bestVal(h + 1, 0), secondBestVal(h + 1, 0);
    vector<int> bestTree(h + 1, -1);
    vector<int> prev(n, 0), cur(n, 0);
    for (int height = 1; height <= h; height++) {
        for (int i = 0; i < n; i++) {
            int same = prev[i];
            int jump = 0;
            if (height >= delta)
                if (bestTree[height - delta] != i)
                    jump = bestVal[height - delta];
                else
                    jump = secondBestVal[height - delta];
            cur[i] = a[i][height] + max(same, jump);
        }
        int best = 0, second = 0, bestT = -1;
        for (int i = 0; i < n; i++) {
            if (cur[i] > best) {
                second = best;
                best   = cur[i];
                bestT  = i;
            } else if (cur[i] > second)
                second = cur[i];
        }
        bestVal[height]       = best;
        bestTree[height]      = bestT;
        secondBestVal[height] = second;
        swap(prev, cur);
    }
    ans = bestVal[h];
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
