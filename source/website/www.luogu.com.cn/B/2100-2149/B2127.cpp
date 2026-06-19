#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

bool isPerfect(int x) {
    int sum = 0;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0) {
            if (i != x)
                sum += i;
            int j = x / i;
            if (j != x && j != i)
                sum += j;
        }
    return sum == x;
}

void process() {
    for (int i = 2; i <= n; i++)
        if (isPerfect(i))
            printf("%d\n", i);
}

int main() {
    input();
    process();
    return 0;
}
