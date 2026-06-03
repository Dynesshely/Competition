#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

int d[MAXN + 1];

int main() {
    for (int i = 1; i <= MAXN; i++)
        for (int j = i + i; j <= MAXN; j += i)
            d[j] += i;

    int s;
    scanf("%d", &s);
    for (int a = s; a <= MAXN; a++) {
        int b = d[a];
        if (b <= MAXN && b != a && d[b] == a) {
            printf("%d %d\n", a, b);
            return 0;
        }
    }
    return 0;
}
