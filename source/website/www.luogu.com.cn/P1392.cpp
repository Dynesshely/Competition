#include <bits/stdc++.h>
using namespace std;

int                 n, m, k;
vector<vector<int>> mat;
vector<int>         cur;

void mergeRow(vector<int> &row) {
    sort(row.begin(), row.end());
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int j = 0; j < k; j++)
        pq.push({cur[0] + row[j], 0, j});
    vector<int> nxt(k);
    for (int t = 0; t < k; t++) {
        auto [val, i, j] = pq.top();
        pq.pop();
        nxt[t] = val;
        if (i + 1 < k)
            pq.push({cur[i + 1] + row[j], i + 1, j});
    }
    cur.swap(nxt);
}

void input() {
    scanf("%d%d%d", &n, &m, &k);
    mat.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
}

void process() {
    sort(mat[0].begin(), mat[0].end());
    cur.assign(mat[0].begin(), mat[0].begin() + k);
    for (int r = 1; r < n; r++)
        mergeRow(mat[r]);
}

void output() {
    for (int i = 0; i < k; i++)
        printf("%d%c", cur[i], i == k - 1 ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
