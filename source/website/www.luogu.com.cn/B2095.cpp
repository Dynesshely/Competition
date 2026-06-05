#include <bits/stdc++.h>
using namespace std;

int    n;
double a[305];
double avg, err;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
}

void process() {
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[minIdx])
            minIdx = i;
        if (a[i] > a[maxIdx])
            maxIdx = i;
    }
    double sum = 0;
    int    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == minIdx || i == maxIdx)
            continue;
        sum += a[i];
        cnt++;
    }
    avg = sum / cnt;
    err = 0;
    for (int i = 0; i < n; i++) {
        if (i == minIdx || i == maxIdx)
            continue;
        double diff = fabs(a[i] - avg);
        if (diff > err)
            err = diff;
    }
}

void output() { printf("%.2lf %.2lf\n", avg, err); }

int main() {
    input();
    process();
    output();
    return 0;
}
