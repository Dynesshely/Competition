#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAXK = 25005, MAXS = 26;
int N, K, S, A[MAXN], B[MAXK], fail[MAXK];
int pA[MAXN][MAXS], pB[MAXK][MAXS];
int less_cnt(int p[][MAXS], int idx, int v) { int s = 0; for (int i = 0; i < v; ++i) s += p[idx][i]; return s; }
int eq_cnt(int p[][MAXS], int idx, int v) { return p[idx][v]; }
int window_less(int p[][MAXS], int r, int l, int v) {
    return less_cnt(p, r, v) - (l > 0 ? less_cnt(p, l - 1, v) : 0);
}
int window_eq(int p[][MAXS], int r, int l, int v) {
    return eq_cnt(p, r, v) - (l > 0 ? eq_cnt(p, l - 1, v) : 0);
}
int main() {
    scanf("%d%d%d", &N, &K, &S);
    for (int i = 0; i < N; ++i) { scanf("%d", &A[i]); A[i]--; }
    for (int i = 0; i < K; ++i) { scanf("%d", &B[i]); B[i]--; }
    for (int i = 0; i < N; ++i) {
        if (i > 0) for (int v = 0; v < MAXS; ++v) pA[i][v] = pA[i - 1][v];
        pA[i][A[i]]++;
    }
    for (int i = 0; i < K; ++i) {
        if (i > 0) for (int v = 0; v < MAXS; ++v) pB[i][v] = pB[i - 1][v];
        pB[i][B[i]]++;
    }
    auto match_B = [&](int i, int j) {
        int w = j;
        return window_less(pB, i, i - w, B[i]) == window_less(pB, j, 0, B[j]) &&
               window_eq(pB, i - 1, i - w, B[i]) == (j > 0 ? window_eq(pB, j - 1, 0, B[j]) : 0);
    };
    auto match_A = [&](int i, int j) {
        int w = j;
        return window_less(pA, i, i - w, A[i]) == window_less(pB, j, 0, B[j]) &&
               window_eq(pA, i - 1, i - w, A[i]) == (j > 0 ? window_eq(pB, j - 1, 0, B[j]) : 0);
    };
    fail[0] = 0;
    for (int i = 1; i < K; ++i) {
        int j = fail[i - 1];
        while (j > 0 && !match_B(i, j)) j = fail[j - 1];
        if (match_B(i, j)) j++;
        fail[i] = j;
    }
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while (j > 0 && !match_A(i, j)) j = fail[j - 1];
        if (match_A(i, j)) j++;
        if (j == K) { ans.push_back(i - K + 2); j = fail[K - 1]; }
    }
    printf("%zu\n", ans.size());
    for (int x : ans) printf("%d\n", x);
    return 0;
}
