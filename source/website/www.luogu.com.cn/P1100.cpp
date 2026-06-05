#include <bits/stdc++.h>
using namespace std;

unsigned int n, ans;

void input() { (void)scanf("%u", &n); }

void process() { ans = (n << 16) | (n >> 16); }

void output() { printf("%u\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
