#include <bits/stdc++.h>
using namespace std;

int a[6][6], rowMax[6], colMin[6];

void input() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int i = 1; i <= 5; i++) {
        rowMax[i] = a[i][1];
        for (int j = 2; j <= 5; j++)
            if (a[i][j] > rowMax[i])
                rowMax[i] = a[i][j];
    }
    for (int j = 1; j <= 5; j++) {
        colMin[j] = a[1][j];
        for (int i = 2; i <= 5; i++)
            if (a[i][j] < colMin[j])
                colMin[j] = a[i][j];
    }
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (a[i][j] == rowMax[i] && a[i][j] == colMin[j]) {
                printf("%d %d %d\n", i, j, a[i][j]);
                return;
            }
    printf("not found\n");
}

int main() {
    input();
    process();
    return 0;
}
