#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[105], n = 0;
    while (true) {
        scanf("%d", &a[n]);
        if (a[n] == 0)
            break;
        ++n;
    }
    for (int i = n - 1; i >= 0; --i) {
        printf("%d%c", a[i], i ? ' ' : '\n');
    }
    return 0;
}
