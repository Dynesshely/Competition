#include <bits/stdc++.h>
using namespace std;

int       n, h[155];
char      g[155][155];
long long ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", g[i]);
}

void process() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            h[j] = (g[i][j] == 'W') ? h[j] + 1 : 0;
        stack<pair<int, int>> st;
        long long             cur = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 1;
            while (!st.empty() && st.top().first >= h[j]) {
                auto [height, count] = st.top();
                st.pop();
                cnt += count;
                cur -= (long long)height * count;
            }
            st.push({h[j], cnt});
            cur += (long long)h[j] * cnt;
            ans += cur;
        }
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
