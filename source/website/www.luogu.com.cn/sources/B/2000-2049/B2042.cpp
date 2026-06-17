#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    if (n % 15 == 0)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    input();
    process();
    return 0;
}
