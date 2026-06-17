#include <bits/stdc++.h>
using namespace std;

int                    N, M;
bool                   isBisq[125001];
vector<int>            bisq;
vector<pair<int, int>> res;

void input() { scanf("%d%d", &N, &M); }

void process() {
    int maxVal = M * M * 2;
    for (int p = 0; p <= M; p++)
        for (int q = p; q <= M; q++) {
            int v = p * p + q * q;
            if (!isBisq[v]) {
                isBisq[v] = true;
                bisq.push_back(v);
            }
        }
    sort(bisq.begin(), bisq.end());
    int K = bisq.size();
    for (int i = 0; i < K; i++) {
        int a = bisq[i];
        for (int j = i + 1; j < K; j++) {
            int b = bisq[j] - a;
            if (a + (N - 1) * b > maxVal)
                break;
            bool ok = true;
            for (int k = 2; k < N; k++)
                if (!isBisq[a + k * b]) {
                    ok = false;
                    break;
                }
            if (ok)
                res.push_back({a, b});
        }
    }
    sort(res.begin(), res.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        if (x.second != y.second)
            return x.second < y.second;
        return x.first < y.first;
    });
}

void output() {
    if (res.empty()) {
        printf("NONE\n");
        return;
    }
    for (auto &p : res)
        printf("%d %d\n", p.first, p.second);
}

int main() {
    input();
    process();
    output();
    return 0;
}
