#include <bits/stdc++.h>
using namespace std;

int m[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n, ans;

int match(int x) {
    int res = 0;
    if (x == 0)
        return m[0];
    while (x) {
        res += m[x % 10];
        x /= 10;
    }
    return res;
}

void input() { scanf("%d", &n); }

void process() {
    n -= 4;
    for (int a = 0; a <= 1111; a++)
        for (int b = 0; b <= 1111; b++)
            if (match(a) + match(b) + match(a + b) == n)
                ans++;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
