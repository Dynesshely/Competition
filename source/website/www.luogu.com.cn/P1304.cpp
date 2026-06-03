#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
bool isPrime[MAXN];

void init(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    for (int x = 4; x <= n; x += 2) {
        for (int p = 2; p <= x / 2; ++p) {
            if (isPrime[p] && isPrime[x - p]) {
                printf("%d=%d+%d\n", x, p, x - p);
                break;
            }
        }
    }
    return 0;
}
