#include <bits/stdc++.h>
using namespace std;

int n, cnt5, cnt0;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 5)
            cnt5++;
        else
            cnt0++;
    }
}

void process() {
    if (cnt0 == 0) {
        printf("-1\n");
        return;
    }
    int useCnt5 = cnt5 - cnt5 % 9;
    if (useCnt5 == 0) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < useCnt5; i++)
        printf("5");
    for (int i = 0; i < cnt0; i++)
        printf("0");
    printf("\n");
}

void output() {}

int main() {
    input();
    process();
    return 0;
}
