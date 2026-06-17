#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int                T;
vector<int>        ns;
vector<vector<ll>> arrays;
vector<ll>         answers;

void input() {
    scanf("%d", &T);
    ns.resize(T);
    arrays.resize(T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        ns[i] = n;
        arrays[i].resize(n);
        for (int j = 0; j < n; ++j)
            scanf("%lld", &arrays[i][j]);
    }
}

void process() {
    answers.resize(T);
    for (int t = 0; t < T; ++t) {
        int        n = ns[t];
        vector<ll> a(n + 1, 0);
        vector<ll> pref(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            a[i]    = arrays[t][i - 1];
            pref[i] = pref[i - 1] + a[i];
        }
        vector<ll> R(n + 2, 0);
        for (int r = 1; r <= n; ++r) {
            ll L = 0;
            for (int l = r; l >= 1; --l) {
                ll dpVal;
                if (l == r)
                    dpVal = a[l];
                else
                    dpVal = (pref[r] - pref[l - 1]) - min(L, R[l]);
                if (dpVal < L)
                    L = dpVal;
                if (dpVal < R[l])
                    R[l] = dpVal;
                if (l == 1 && r == n)
                    answers[t] = dpVal;
            }
        }
    }
}

void output() {
    for (int i = 0; i < T; ++i)
        printf("%lld\n", answers[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
