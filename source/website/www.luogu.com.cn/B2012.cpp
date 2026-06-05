#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    double ans = (double)b / a * 100;
    printf("%.3f%%\n", ans);
    return 0;
}
