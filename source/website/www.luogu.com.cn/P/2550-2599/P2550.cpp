#include <bits/stdc++.h>
using namespace std;

int n, win[35], res[7];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) {
        int x;
        scanf("%d", &x);
        win[x] = 1;
    }
}

void process() {
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 7; j++) {
            int x;
            scanf("%d", &x);
            if (win[x])
                cnt++;
        }
        if (cnt)
            res[7 - cnt]++;
    }
}

void output() {
    for (int i = 0; i < 7; i++) {
        if (i)
            printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
