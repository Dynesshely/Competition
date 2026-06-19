#include <bits/stdc++.h>
using namespace std;

char s[105];

void input() { fgets(s, 105, stdin); }

void process() {
    int len = strlen(s);
    if (s[len - 1] == '\n')
        s[--len] = '\0';
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            for (int j = i - 1; j >= start; j--)
                putchar(s[j]);
            putchar('\n');
            start = i + 1;
        }
    }
}

int main() {
    input();
    process();
    return 0;
}
