#include <bits/stdc++.h>
using namespace std;

int n;
int cnt1, cnt2, cnt3, cnt4;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a <= 18)
            cnt1++;
        else if (a <= 35)
            cnt2++;
        else if (a <= 60)
            cnt3++;
        else
            cnt4++;
    }
}

void output() { printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n", cnt1 * 100.0 / n, cnt2 * 100.0 / n, cnt3 * 100.0 / n, cnt4 * 100.0 / n); }

int main() {
    input();
    process();
    output();
    return 0;
}
