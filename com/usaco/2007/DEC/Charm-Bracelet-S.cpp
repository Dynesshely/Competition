#include <bits/stdc++.h>

const int maxn = 114514;
int N, M, W[maxn], V[maxn], f[maxn];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &W[i], &V[i]);
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= W[i]; --j) {
            if(f[j-W[i]] + V[i] > f[j]) f[j] = f[j-W[i]] + V[i];
        }
    }
    printf("%d\n", f[M]);
    return 0;
}
