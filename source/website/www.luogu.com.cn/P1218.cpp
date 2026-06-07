#include <bits/stdc++.h>
using namespace std;

int         n;
vector<int> primes;

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int p : primes) {
        if (p * p > x)
            return true;
        if (x % p == 0)
            return false;
    }
    return true;
}

void dfs(int cur, int len) {
    if (len == n) {
        printf("%d\n", cur);
        return;
    }
    for (int d : {1, 3, 7, 9}) {
        int nxt = cur * 10 + d;
        if (isPrime(nxt))
            dfs(nxt, len + 1);
    }
}

int main() {
    scanf("%d", &n);
    const int    limit = 10000;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++)
        if (is_prime[i])
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
    for (int i = 2; i <= limit; i++)
        if (is_prime[i])
            primes.push_back(i);
    for (int start : {2, 3, 5, 7})
        dfs(start, 1);
    return 0;
}
