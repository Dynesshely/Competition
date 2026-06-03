#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double hp = 10.0;
    int exp = 0;
    for (int i = 0; i < n; i++) {
        double x, a;
        scanf("%lf%lf", &x, &a);
        hp -= x;
        if (hp <= 0) break;
        if (hp > 10.0) hp = 10.0;
        exp += (int)a;
    }
    int level = 0;
    int need = 1;
    while (exp >= need) {
        exp -= need;
        level++;
        need <<= 1;
    }
    printf("%d %d\n", level, exp);
    return 0;
}
