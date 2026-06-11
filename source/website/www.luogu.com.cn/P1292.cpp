#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll                a, b, g, x, y;
void              exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if (b == 0) {
        g = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, g, y, x);
        y -= x * (a / b);
    }
}
ll ceilDiv(ll p, ll q) {
    if (p >= 0)
        return (p + q - 1) / q;
    else
        return p / q;
}
void input() { scanf("%lld%lld", &a, &b); }
void process() {
    exgcd(a, b, g, x, y);
    ll t  = max(ceilDiv(x * g, b), ceilDiv(-y * g, a));
    ll pa = -x + t * (b / g);
    ll pb = y + t * (a / g);
    printf("%lld\n%lld %lld\n", g, pa, pb);
}
int main() {
    input();
    process();
    return 0;
}
