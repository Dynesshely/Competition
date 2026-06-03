#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigInt {
    int d[65], len; // base 10^9, max 65*9=585 digits
    BigInt() { memset(d, 0, sizeof(d)); len = 1; }
    BigInt(int x) {
        memset(d, 0, sizeof(d));
        len = 0;
        if (x == 0) { len = 1; return; }
        while (x) { d[len++] = x % 1000000000; x /= 1000000000; }
    }
    void add(const BigInt &b) {
        int carry = 0;
        len = max(len, b.len);
        for (int i = 0; i < len; ++i) {
            d[i] += b.d[i] + carry;
            carry = d[i] / 1000000000;
            d[i] %= 1000000000;
        }
        if (carry) d[len++] = carry;
    }
    void sub(const BigInt &b) {
        int borrow = 0;
        for (int i = 0; i < len; ++i) {
            d[i] -= b.d[i] + borrow;
            if (d[i] < 0) { d[i] += 1000000000; borrow = 1; }
            else borrow = 0;
        }
        while (len > 1 && d[len - 1] == 0) --len;
    }
    void mul(int x) {
        long long carry = 0;
        for (int i = 0; i < len; ++i) {
            carry += (long long)d[i] * x;
            d[i] = carry % 1000000000;
            carry /= 1000000000;
        }
        while (carry) { d[len++] = carry % 1000000000; carry /= 1000000000; }
    }
    void div(int x) {
        long long rem = 0;
        for (int i = len - 1; i >= 0; --i) {
            rem = rem * 1000000000 + d[i];
            d[i] = rem / x;
            rem %= x;
        }
        while (len > 1 && d[len - 1] == 0) --len;
    }
    void print() {
        printf("%d", d[len - 1]);
        for (int i = len - 2; i >= 0; --i)
            printf("%09d", d[i]);
        printf("\n");
    }
};

BigInt C(int n, int k) {
    if (k < 0 || k > n) return BigInt(0);
    if (k > n - k) k = n - k;
    BigInt r(1);
    for (int i = 1; i <= k; ++i) {
        r.mul(n - k + i);
        r.div(i);
    }
    return r;
}

int main() {
    int k, w;
    scanf("%d%d", &k, &w);
    int B = 1 << k;
    int maxL = (w + k - 1) / k; // ceil(w/k)
    BigInt ans(0);
    for (int L = 2; L <= maxL; ++L) {
        int b = w - (L - 1) * k;
        if (b <= 0) continue;
        int M = (b >= k) ? (B - 1) : ((1 << b) - 1);
        if (M > B - 1) M = B - 1;
        BigInt cur = C(B - 1, L);
        if (B - 1 - M >= L) {
            BigInt sub = C(B - 1 - M, L);
            cur.sub(sub);
        }
        ans.add(cur);
    }
    ans.print();
    return 0;
}
