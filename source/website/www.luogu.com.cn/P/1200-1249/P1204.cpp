#include <bits/stdc++.h>
using namespace std;

int            n;
pair<int, int> a[5005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
}

void process() { sort(a, a + n); }

void output() {
    int curStart = a[0].first, curEnd = a[0].second;
    int milking = curEnd - curStart, idle = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first > curEnd) {
            int gap = a[i].first - curEnd;
            if (gap > idle)
                idle = gap;
            curStart = a[i].first;
            curEnd   = a[i].second;
        } else if (a[i].second > curEnd)
            curEnd = a[i].second;
        int len = curEnd - curStart;
        if (len > milking)
            milking = len;
    }
    printf("%d %d\n", milking, idle);
}

int main() {
    input();
    process();
    output();
    return 0;
}
