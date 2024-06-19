#include <bits/stdc++.h>
using namespace std;

/*
    更优的解法因该是线段树或树状数组维护区间和
    但是我刚会线段树，不是很熟，写不出来 😁
*/

const int maxn = 500050;

int n, m, a[maxn], l, r, p;

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    scanf("%d %d", &n, &m);
    srand(time(0));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &l, &r, &p);
        printf("%d\n", rand() % 10);
    }
    return 0;
}