#include <bits/stdc++.h>
using namespace std;

int main() {
    int day = 0, mx = 0;
    for (int i = 1; i <= 7; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a + b > mx) { mx = a + b; day = i; }
    }
    printf("%d\n", mx > 8 ? day : 0);
    return 0;
}
