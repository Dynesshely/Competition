#include <bits/stdc++.h>
using namespace std;

int               n;
long long         k;
long long         fact[15];
vector<long long> lucky;

void genLucky(long long limit, long long cur) {
    if (cur > limit)
        return;
    if (cur > 0)
        lucky.push_back(cur);
    genLucky(limit, cur * 10 + 4);
    genLucky(limit, cur * 10 + 7);
}

bool isLucky(long long x) {
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7)
            return false;
        x /= 10;
    }
    return true;
}

void input() { scanf("%d%lld", &n, &k); }

void process() {
    fact[0] = 1;
    for (int i = 1; i <= 13; i++)
        fact[i] = fact[i - 1] * i;
    if (n <= 12 && k > fact[n]) {
        printf("-1");
        return;
    }
    int m = 0;
    for (int i = 1; i <= 13; i++)
        if (fact[i] >= k) {
            m = i;
            break;
        }
    if (m > n) {
        printf("-1");
        return;
    }
    int prefixLen = n - m;
    lucky.clear();
    genLucky(prefixLen, 0);
    int         ans = (int)lucky.size();
    vector<int> nums(m);
    iota(nums.begin(), nums.end(), 1);
    vector<int> perm(m);
    long long   k0 = k - 1;
    for (int i = 0; i < m; i++) {
        int f   = m - 1 - i;
        int idx = (int)(k0 / fact[f]);
        perm[i] = nums[idx];
        nums.erase(nums.begin() + idx);
        k0 %= fact[f];
    }
    for (int i = 0; i < m; i++) {
        long long pos = (long long)prefixLen + i + 1;
        long long val = (long long)prefixLen + perm[i];
        if (isLucky(pos) && isLucky(val))
            ans++;
    }
    printf("%d", ans);
}

void output() {}

int main() {
    input();
    process();
    return 0;
}
