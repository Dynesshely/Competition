#include <bits/stdc++.h>
using namespace std;

int k, x, cnt1, cnt5, cnt10;

void input() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        if (x == 1)
            cnt1++;
        else if (x == 5)
            cnt5++;
        else if (x == 10)
            cnt10++;
    }
}

void process() {}

void output() { printf("%d\n%d\n%d\n", cnt1, cnt5, cnt10); }

int main() {
    input();
    process();
    output();
    return 0;
}
