#include <bits/stdc++.h>
using namespace std;

int  x, y, i, ans;
bool via[241][241];

int main() {
    scanf("%d%d%d", &x, &y, &i);
    while (i--) {
        int xll, yll, xur, yur;
        scanf("%d%d%d%d", &xll, &yll, &xur, &yur);
        for (int r = xll; r <= xur; ++r)
            for (int c = yll; c <= yur; ++c)
                if (!via[r][c]) {
                    via[r][c] = true;
                    ++ans;
                }
    }
    printf("%d\n", ans);
    return 0;
}
