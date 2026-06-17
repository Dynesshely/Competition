#include <bits/stdc++.h>
using namespace std;

int  n;
char a[12][12], b[12][12];

bool isEqual(char x[12][12], char y[12][12]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (x[i][j] != y[i][j])
                return false;
    return true;
}

void rotate90(char src[12][12], char dst[12][12]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dst[i][j] = src[n - 1 - j][i];
}

void reflect(char src[12][12], char dst[12][12]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dst[i][j] = src[i][n - 1 - j];
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < n; i++)
        scanf("%s", b[i]);
}

int process() {
    char t[12][12], t2[12][12];

    rotate90(a, t);
    if (isEqual(t, b))
        return 1;

    rotate90(t, t2);
    if (isEqual(t2, b))
        return 2;

    rotate90(t2, t);
    if (isEqual(t, b))
        return 3;

    reflect(a, t);
    if (isEqual(t, b))
        return 4;

    rotate90(t, t2);
    if (isEqual(t2, b))
        return 5;

    rotate90(t2, t);
    if (isEqual(t, b))
        return 5;

    rotate90(t, t2);
    if (isEqual(t2, b))
        return 5;

    if (isEqual(a, b))
        return 6;

    return 7;
}

void output() { printf("%d\n", process()); }

int main() {
    input();
    output();
    return 0;
}
