#include <bits/stdc++.h>
using namespace std;

int n, last, cur;
bool seen[1010];

int main() {
    scanf("%d%d", &n, &last);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &cur);
        int d = abs(cur - last);
        if (d > 0 && d < n) seen[d] = true;
        last = cur;
    }
    for (int i = 1; i < n; ++i)
        if (!seen[i]) { printf("Not jolly\n"); return 0; }
    printf("Jolly\n");
    return 0;
}
