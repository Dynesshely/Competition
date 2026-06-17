#include <bits/stdc++.h>
using namespace std;

int a, b, res;

void input() { scanf("%d %d", &a, &b); }

void process() {
    int base = a % 7;
    res      = 1;
    while (b) {
        if (b & 1)
            res = (res * base) % 7;
        base = (base * base) % 7;
        b >>= 1;
    }
}

void output() {
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("%s\n", days[res]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
