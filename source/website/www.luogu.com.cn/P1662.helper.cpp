#include <bits/stdc++.h>
using namespace std;
const int maxx = 10010000;
int       T, x;
bool      via[maxx];
bool      c7(int x) {
    int remain = 0;
    while (x) {
        remain = x % 10;
        if (remain == 7)
            return true;
        x = x / 10;
    }
    return false;
}
int main() {
    for (int i = 2; i <= maxx; ++i)
        if (via[i] == 0 && (c7(i) || i % 7 == 0))
            via[i] = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        if (via[i])
            printf("%d\n", i);
    }
    return 0;
}