#include <bits/stdc++.h>
using namespace std;

int  d;
bool ok;

void input() { scanf("%d", &d); }

void process() {
    if (d == 1 || d == 3 || d == 5)
        ok = false;
    else
        ok = true;
}

void output() {
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
