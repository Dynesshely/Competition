#include <bits/stdc++.h>
using namespace std;

int            n;
pair<int, int> a[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
}

void process() { sort(a, a + n); }

void output() {
    long long total = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i)
            printf(" ");
        printf("%d", a[i].second);
        total += sum;
        sum += a[i].first;
    }
    printf("\n%.2f\n", (double)total / n);
}

int main() {
    input();
    process();
    output();
    return 0;
}
