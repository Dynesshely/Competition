#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, m, n;
    scanf("%d%d%d", &k, &m, &n);
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if (a == 0) {
            if (b > 0)
                ans.push_back(i);
        } else {
            if ((long long)(k / a) * b >= n)
                ans.push_back(i);
        }
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i > 0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
