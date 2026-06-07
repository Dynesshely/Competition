#include <bits/stdc++.h>
using namespace std;

int  n, digits[10];
bool used[10];

bool checkDigits(int x, int len) {
    int lo = 1;
    for (int i = 1; i < len; i++)
        lo *= 10;
    int hi = lo * 10;
    if (x < lo || x >= hi)
        return false;
    while (x) {
        if (!used[x % 10])
            return false;
        x /= 10;
    }
    return true;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
        used[digits[i]] = true;
    }
}

void process() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        if (!checkDigits(a, 3))
            continue;
        for (int b = 10; b < 100; b++) {
            if (!checkDigits(b, 2))
                continue;
            int p1   = a * (b % 10);
            int p2   = a * (b / 10);
            int prod = a * b;
            if (checkDigits(p1, 3) && checkDigits(p2, 3) && checkDigits(prod, 4))
                ans++;
        }
    }
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
