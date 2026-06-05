#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void writeInt(ll x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10) writeInt(x / 10);
    putchar('0' + x % 10);
}

ll n;

int main() {
    scanf("%lld", &n);
    while (n != 1) {
        writeInt(n);
        if (n & 1) { n = n * 3 + 1; printf("*3+1="); }
        else       { n >>= 1;        printf("/2="); }
        writeInt(n);
        putchar('\n');
    }
    printf("End\n");
    return 0;
}
