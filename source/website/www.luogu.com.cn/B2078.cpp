#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m;
    int       k;
    scanf("%lld%d", &m, &k);
    int cnt = 0;
    while (m) {
        if (m % 10 == 3)
            ++cnt;
        m /= 10;
    }
    printf(cnt == k ? "YES" : "NO");
    return 0;
}
