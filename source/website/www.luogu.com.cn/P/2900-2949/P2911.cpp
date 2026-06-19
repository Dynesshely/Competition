#include <bits/stdc++.h>
using namespace std;

int s1, s2, s3, cnt[81], ans, maxCnt;

int main() {
    scanf("%d%d%d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; ++i)
        for (int j = 1; j <= s2; ++j)
            for (int k = 1; k <= s3; ++k)
                ++cnt[i + j + k];
    for (int i = 3; i <= s1 + s2 + s3; ++i)
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
            ans    = i;
        }
    printf("%d\n", ans);
    return 0;
}
