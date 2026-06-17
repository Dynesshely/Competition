#include <bits/stdc++.h>
using namespace std;

char s[10];
int  c[30][10];

void init() {
    for (int i = 0; i <= 26; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= min(i, 6); j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

void input() { scanf("%s", s); }

void process() {
    int len = strlen(s);
    if (len > 6) {
        printf("0\n");
        return;
    }
    for (int i = 1; i < len; i++)
        if (s[i] <= s[i - 1]) {
            printf("0\n");
            return;
        }
    for (int i = 0; i < len; i++)
        if (s[i] < 'a' || s[i] > 'z') {
            printf("0\n");
            return;
        }
    int ans = 0;
    for (int k = 1; k < len; k++)
        ans += c[26][k];
    int prev = 0;
    for (int i = 0; i < len; i++) {
        int cur = s[i] - 'a' + 1;
        int rem = len - i - 1;
        for (int letter = prev + 1; letter < cur; letter++)
            ans += c[26 - letter][rem];
        prev = cur;
    }
    printf("%d\n", ans + 1);
}

void output() {}

int main() {
    init();
    input();
    process();
    return 0;
}
