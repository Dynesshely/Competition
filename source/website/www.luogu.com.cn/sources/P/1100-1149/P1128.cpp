#include <bits/stdc++.h>
using namespace std;

const int MAXP         = 60;
const int primes[MAXP] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                          127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281};

int         n;
vector<int> divs;
int         bestExp[MAXP], curExp[MAXP];
long double bestLog;

void genDivs(int x) {
    divs.clear();
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i != 1)
                divs.push_back(i);
            if (i * i != x && x / i != 1)
                divs.push_back(x / i);
        }
    }
    sort(divs.rbegin(), divs.rend());
}

void dfs(int idx, int rem, int prev) {
    if (rem == 1) {
        long double cur = 0.0L;
        for (int i = 0; i < idx; i++)
            cur += (long double)curExp[i] * logl((long double)primes[i]);
        if (cur < bestLog) {
            bestLog = cur;
            for (int i = 0; i < idx; i++)
                bestExp[i] = curExp[i];
            for (int i = idx; i < MAXP; i++)
                bestExp[i] = 0;
        }
        return;
    }
    for (int d : divs) {
        if (d > prev || d > rem)
            continue;
        if (rem % d == 0) {
            curExp[idx] = d - 1;
            dfs(idx + 1, rem / d, d);
        }
    }
}

struct BigInt {
    static const int BASE = 1000000000;
    vector<int>      d;
    BigInt()
        : d(1, 0) {}
    BigInt(int x) {
        d.clear();
        while (x) {
            d.push_back(x % BASE);
            x /= BASE;
        }
        if (d.empty())
            d.push_back(0);
    }
    void mul(int x) {
        long long carry = 0;
        for (int i = 0; i < (int)d.size(); i++) {
            carry += (long long)d[i] * x;
            d[i] = carry % BASE;
            carry /= BASE;
        }
        while (carry) {
            d.push_back(carry % BASE);
            carry /= BASE;
        }
    }
    void print() {
        printf("%d", d.back());
        for (int i = (int)d.size() - 2; i >= 0; i--)
            printf("%09d", d[i]);
        printf("\n");
    }
};

void input() { scanf("%d", &n); }

void process() {
    if (n == 1)
        return;
    genDivs(n);
    bestLog = 1e100L;
    dfs(0, n, n);
}

void output() {
    if (n == 1) {
        printf("1\n");
        return;
    }
    BigInt ans(1);
    for (int i = 0; i < MAXP && bestExp[i] > 0; i++)
        for (int j = 0; j < bestExp[i]; j++)
            ans.mul(primes[i]);
    ans.print();
}

int main() {
    input();
    process();
    output();
    return 0;
}
