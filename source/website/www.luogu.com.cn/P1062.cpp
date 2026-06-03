#include <cstdio>

int main() {
    int k, N;
    scanf("%d%d", &k, &N);
    long long ans = 0, pw = 1;
    while (N) {
        if (N & 1) ans += pw;
        pw *= k;
        N >>= 1;
    }
    printf("%lld\n", ans);
    return 0;
}
