#include <bits/stdc++.h>
using namespace std;

char s[110];
int  len;

void input() {
    fgets(s, 110, stdin);
    len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
        s[--len] = '\0';
}

void process() {}

void output() {
    for (int i = 0; i < len; i++)
        printf("%c", s[i] + s[(i + 1) % len]);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
