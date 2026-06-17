#include <bits/stdc++.h>
using namespace std;

double s;

void input() { scanf("%lf", &s); }

void process() {
    int    steps = 0;
    double cur = 2.0, dist = 0.0;
    while (dist < s) {
        dist += cur;
        cur *= 0.98;
        ++steps;
    }
    printf("%d\n", steps);
}

int main() {
    input();
    process();
    return 0;
}
