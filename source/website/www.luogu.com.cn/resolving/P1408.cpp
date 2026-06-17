#include <bits/stdc++.h>
using namespace std;

int       n, a[10010];
long long ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void process() {
    const int    MAXP = 5000;
    vector<int>  primes;
    vector<char> isPrime(MAXP + 1, 1);
    for (int i = 2; i <= MAXP; i++)
        if (isPrime[i]) {
            primes.push_back(i);
            if (1LL * i * i <= MAXP)
                for (int j = i * i; j <= MAXP; j += i)
                    isPrime[j] = 0;
        }

    vector<pair<int, pair<int, int>>> factors;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int p : primes) {
            if (1LL * p * p > x)
                break;
            if (x % p == 0) {
                int exp = 0;
                while (x % p == 0) {
                    x /= p;
                    exp++;
                }
                factors.push_back({p, {i, exp}});
            }
        }
        if (x > 1)
            factors.push_back({x, {i, 1}});
    }

    sort(factors.begin(), factors.end());

    ans          = 0;
    int curPrime = 0, prevIdx = -1, cur = 0;
    for (size_t i = 0; i < factors.size(); i++) {
        int p   = factors[i].first;
        int idx = factors[i].second.first;
        int exp = factors[i].second.second;

        if (i == 0 || p != curPrime) {
            curPrime = p;
            prevIdx  = -1;
            cur      = 0;
        }

        if (prevIdx == -1)
            cur = exp;
        else if (idx == prevIdx + 1) {
            int k = min(cur, exp);
            ans += 1LL * k * p;
            cur = exp - k;
        } else
            cur = exp;
        prevIdx = idx;
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
