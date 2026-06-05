#include <bits/stdc++.h>
using namespace std;

int a[5], eaten;

void input() {
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
}

void process() {
    eaten = 0;
    for (int i = 0; i < 5; i++) {
        int give = a[i] / 3;
        int eat  = a[i] - give * 3;
        eaten += eat;
        a[i]  = give;
        int l = (i - 1 + 5) % 5;
        int r = (i + 1) % 5;
        a[l] += give;
        a[r] += give;
    }
}

void output() {
    for (int i = 0; i < 5; i++) {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", eaten);
}

int main() {
    input();
    process();
    output();
    return 0;
}
