#include <bits/stdc++.h>
using namespace std;

int         n, m;
vector<int> a;

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    while (m--) {
        int q;
        scanf("%d", &q);
        printf("%d\n", a[q - 1]);
    }
    return 0;
}
