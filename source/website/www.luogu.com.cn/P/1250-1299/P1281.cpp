#include <bits/stdc++.h>
using namespace std;

int m, k, pages[505], ansL[505], ansR[505];

bool check(int limit) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < m; i++) {
        if (pages[i] > limit)
            return false;
        if (sum + pages[i] > limit) {
            cnt++;
            sum = pages[i];
        } else
            sum += pages[i];
    }
    return cnt <= k;
}

void input() {
    scanf("%d%d", &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d", &pages[i]);
}

void process() {
    int lo = 0, hi = 0;
    for (int i = 0; i < m; i++) {
        if (pages[i] > lo)
            lo = pages[i];
        hi += pages[i];
    }
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    int maxPages = lo, cur = m - 1;
    for (int i = k - 1; i >= 0; i--) {
        int sum = 0, end = cur;
        while (cur >= i && sum + pages[cur] <= maxPages) {
            sum += pages[cur];
            cur--;
        }
        ansL[i] = cur + 1;
        ansR[i] = end;
    }
}

void output() {
    for (int i = 0; i < k; i++)
        printf("%d %d\n", ansL[i] + 1, ansR[i] + 1);
}

int main() {
    input();
    process();
    output();
    return 0;
}
