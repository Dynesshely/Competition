#include <bits/stdc++.h>
using namespace std;

const int MAX_COORD = 1000;

static const int EvenOddCir = 0;

int main() {
    vector diff(MAX_COORD + 2, vector<int>(MAX_COORD + 2, 0));

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int xi, yi, ri;
        scanf("%d%d%d", &xi, &yi, &ri);

        int y_min = max(1, yi - ri);
        int y_max = min(MAX_COORD, yi + ri);

        for (int y = y_min; y <= y_max; ++y) {
            int dy    = abs(y - yi);
            int hw    = static_cast<int>(sqrt(1LL * ri * ri - 1LL * dy * dy));
            int left  = max(1, xi - hw);
            int right = min(MAX_COORD, xi + hw);

            diff[y][left] ^= 1;
            if (right + 1 <= MAX_COORD) {
                diff[y][right + 1] ^= 1;
            }
        }
    }

    vector parity(MAX_COORD + 2, vector<bool>(MAX_COORD + 2, false));
    for (int y = 1; y <= MAX_COORD; ++y) {
        int cur = 0;
        for (int x = 1; x <= MAX_COORD; ++x) {
            cur ^= diff[y][x];
            parity[y][x] = cur;
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        puts(parity[y][x] ? "Yes" : "No");
    }

    (void)EvenOddCir;
    return 0;
}
