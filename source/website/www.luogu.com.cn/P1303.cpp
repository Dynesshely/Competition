#include <bits/stdc++.h>
using namespace std;

char aStr[2010], bStr[2010];
int  a[2010], b[2010], res[4010];
int  lenA, lenB, lenRes;

void input() { scanf("%s%s", aStr, bStr); }

void process() {
    lenA = strlen(aStr);
    lenB = strlen(bStr);
    for (int i = 0; i < lenA; i++)
        a[i] = aStr[lenA - 1 - i] - '0';
    for (int i = 0; i < lenB; i++)
        b[i] = bStr[lenB - 1 - i] - '0';
    for (int i = 0; i < lenA; i++)
        for (int j = 0; j < lenB; j++)
            res[i + j] += a[i] * b[j];
    lenRes = lenA + lenB;
    for (int i = 0; i < lenRes; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (lenRes > 1 && res[lenRes - 1] == 0)
        lenRes--;
}

void output() {
    for (int i = lenRes - 1; i >= 0; i--)
        printf("%d", res[i]);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
