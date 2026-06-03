#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &s[i], &e[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool cover[1000] = {false};
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int t = s[j]; t < e[j]; t++)
                cover[t] = true;
        }
        int cnt = 0;
        for (int t = 0; t < 1000; t++)
            if (cover[t]) cnt++;
        if (cnt > ans) ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
