#include <bits/stdc++.h>
using namespace std;

int  n;
char w[105][25];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", w[i]);
}

void process() {
    for (int i = 0; i < n; i++) {
        int len = strlen(w[i]);
        if (w[i][0] >= 'a' && w[i][0] <= 'z')
            w[i][0] = w[i][0] - 'a' + 'A';
        for (int j = 1; j < len; j++)
            if (w[i][j] >= 'A' && w[i][j] <= 'Z')
                w[i][j] = w[i][j] - 'A' + 'a';
    }
}

void output() {
    for (int i = 0; i < n; i++)
        printf("%s\n", w[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
