#include <bits/stdc++.h>
using namespace std;

int  x;
char c;

void input() { scanf("%d %c", &x, &c); }

void process() {
    int fee = 8;
    if (x > 1000)
        fee += (x - 1000 + 499) / 500 * 4;
    if (c == 'y')
        fee += 5;
    printf("%d\n", fee);
}

int main() {
    input();
    process();
    return 0;
}
