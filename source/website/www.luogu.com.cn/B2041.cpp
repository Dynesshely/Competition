#include <bits/stdc++.h>
using namespace std;

int lucky, encourage, ans;

void input() { scanf("%d%d", &lucky, &encourage); }

void process() { ans = (lucky >= 10 || encourage >= 20) ? 1 : 0; }

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
