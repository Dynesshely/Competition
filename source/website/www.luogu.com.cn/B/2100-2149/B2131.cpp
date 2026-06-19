#include <bits/stdc++.h>
using namespace std;

int   n;
char  names[205][10];
float temps[205];
int   cough[205];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s%f%d", names[i], &temps[i], &cough[i]);
}

void process() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (temps[i] >= 37.5f && cough[i] == 1) {
            printf("%s\n", names[i]);
            cnt++;
        }
    printf("%d\n", cnt);
}

int main() {
    input();
    process();
    return 0;
}
