#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    vector<int> k_vals(m);
    for (int i = 0; i < m; ++i) {
        cin >> k_vals[i];
    }

    for (int q = 0; q < m; ++q) {
        int k = k_vals[q];

        ll cur_max = 0, best_max = 0;
        ll cur_min = 0, best_min = 0;

        for (int i = 0; i < n; ++i) {
            ll delta = static_cast<ll>(a[i] ^ k) - a[i];

            cur_max = max(delta, cur_max + delta);
            best_max = max(best_max, cur_max);

            cur_min = min(delta, cur_min + delta);
            best_min = min(best_min, cur_min);
        }

        ll ans_min = total + best_min;
        ll ans_max = total + best_max;

        cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}
