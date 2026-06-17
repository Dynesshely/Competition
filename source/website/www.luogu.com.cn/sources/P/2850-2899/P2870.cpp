#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 500005;
const ull BASE = 131;
char s[MAXN];
ull fw[MAXN], rv[MAXN], bp[MAXN];
int n;
ull geth(ull *h, int l, int r) { return h[r] - h[l - 1] * bp[r - l + 1]; }
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf(" %c", &s[i]);
    bp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fw[i] = fw[i - 1] * BASE + s[i];
        bp[i] = bp[i - 1] * BASE;
    }
    for (int i = n; i >= 1; --i) rv[n - i + 1] = rv[n - i] * BASE + s[i];
    string ans;
    int l = 1, r = n;
    while (l <= r) {
        if (s[l] < s[r]) { ans += s[l++]; continue; }
        if (s[l] > s[r]) { ans += s[r--]; continue; }
        int lo = 0, hi = (r - l + 1) / 2;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (geth(fw, l, l + mid - 1) == geth(rv, n - r + 1, n - r + mid))
                lo = mid;
            else hi = mid - 1;
        }
        int pos = lo;
        char cl = (pos < (r - l + 1) / 2) ? s[l + pos] : 0;
        char cr = (pos < (r - l + 1) / 2) ? s[r - pos] : 0;
        if (cl <= cr) ans += s[l++]; else ans += s[r--];
    }
    for (size_t i = 0; i < ans.size(); ++i) {
        putchar(ans[i]);
        if ((i + 1) % 80 == 0) putchar('\n');
    }
    if (ans.size() % 80) putchar('\n');
    return 0;
}
