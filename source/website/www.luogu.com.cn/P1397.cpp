#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll          MOD = 1000000007;
const ll          PHI = MOD - 1;

char nStr[1000005], mStr[1000005];
ll   a, b, c, d;

ll powMod(ll x, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return r;
}

ll inv(ll x) { return powMod(x, MOD - 2); }

ll modMinusOne(const char *s, ll mod) {
    ll r = 0;
    for (int i = 0; s[i]; i++)
        r = (r * 10 + (s[i] - '0')) % mod;
    return (r - 1 + mod) % mod;
}

void input() { scanf("%s%s%lld%lld%lld%lld", nStr, mStr, &a, &b, &c, &d); }

void process() {
    ll mMod = modMinusOne(mStr, MOD);
    ll mExp = modMinusOne(mStr, PHI);
    ll nMod = modMinusOne(nStr, MOD);
    ll nExp = modMinusOne(nStr, PHI);

    ll A, B;
    if (a == 1) {
        A = c % MOD;
        B = (c % MOD * mMod % MOD * (b % MOD) % MOD + d % MOD) % MOD;
    } else {
        ll am1   = powMod(a % MOD, mExp);
        ll invA1 = inv((a - 1) % MOD);
        A        = c % MOD * am1 % MOD;
        B        = (c % MOD * (b % MOD) % MOD * (am1 - 1 + MOD) % MOD * invA1 % MOD + d % MOD) % MOD;
    }

    ll rowN;
    if (nStr[0] == '1' && nStr[1] == '\0') {
        rowN = 1;
    } else if (A == 1) {
        rowN = (1 + nMod * B % MOD) % MOD;
    } else {
        ll An1   = powMod(A, nExp);
        ll invA1 = inv((A - 1 + MOD) % MOD);
        rowN     = (An1 + B % MOD * (An1 - 1 + MOD) % MOD * invA1 % MOD) % MOD;
    }

    ll ans;
    if (a == 1) {
        ans = (rowN + mMod * (b % MOD) % MOD) % MOD;
    } else {
        ll am1   = powMod(a % MOD, mExp);
        ll invA1 = inv((a - 1) % MOD);
        ans      = (am1 * rowN % MOD + (b % MOD) * (am1 - 1 + MOD) % MOD * invA1 % MOD) % MOD;
    }

    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
