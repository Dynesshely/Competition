#include <bits/stdc++.h>
using namespace std;

int    n, x, sum;
double avg;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
    }
    avg = (double)sum / n;
}

void output() { printf("%d %.5lf\n", sum, avg); }

int main() {
    input();
    process();
    output();
    return 0;
}
