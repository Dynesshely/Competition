#include <bits/stdc++.h>

int main() {
    int n, *a = new int[110], x = 1;
    scanf("%d", &n);
    for (int i = 0; i < n + 1; ++i)
        scanf("%d", &a[i]);
    bool highestPrinted = false;
    for (int i = 0, z = n; i < n + 1; ++i, --z) {
        int rst = a[i] * std::pow(x, z);
        if (rst == 0)
            continue;
        if (z == 0) {
            if (rst > 0 && highestPrinted)
                putchar('+');
            printf("%d", rst);
            break;
        }
        if (rst > 0 && highestPrinted)
            putchar('+');
        if (a[i] == 1) {
            putchar('x');
            if (z != 1)
                printf("^%d", z);
        } else if (a[i] == -1) {
            if (z != 1)
                printf("-x^%d", z);
            else
                printf("-x");
        } else {
            if (z != 1)
                printf("%dx^%d", a[i], z);
            else
                printf("%dx", a[i]);
        }
        highestPrinted = true;
    }
    putchar('\n');
    delete[] a;
    return 0;
}