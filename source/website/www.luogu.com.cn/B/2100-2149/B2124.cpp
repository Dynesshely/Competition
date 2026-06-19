#include <bits/stdc++.h>
using namespace std;

char s[105];

void input() { scanf("%s", s); }

void process() {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i]) {
            printf("no\n");
            return;
        }
    printf("yes\n");
}

int main() {
    input();
    process();
    return 0;
}
