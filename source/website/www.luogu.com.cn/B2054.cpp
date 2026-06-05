#include <bits/stdc++.h>
using namespace std;

int    n, a, sum;
double avg;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a), sum += a;
}

void process() { avg = (double)sum / n; }

void output() { printf("%.2f\n", avg); }

int main() {
    input();
    process();
    output();
    return 0;
}
