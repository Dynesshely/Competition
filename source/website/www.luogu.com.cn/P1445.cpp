#include <bits/stdc++.h>
using namespace std;

const int MOD  = 1000000007;
const int MAXN = 1000000;

int              n;
vector<int>      primes;
bitset<MAXN + 1> isPrime;

void input() { scanf("%d", &n); }

void process() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

void output() {
    long long ans = 1;
    for (int p : primes) {
        long long e = 0;
        for (long long pk = p; pk <= n; pk *= p)
            e += n / pk;
        ans = ans * (2 * e + 1) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
