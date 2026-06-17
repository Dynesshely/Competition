#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

void input() { scanf("%d%d", &n, &k); }

void process() { ans = n / k; }

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
