#include <bits/stdc++.h>
using namespace std;

char s[1005];
int  first = 1;

void input() { fgets(s, 1005, stdin); }

void process() {
    int len = strlen(s);
    if (s[len - 1] == '\n')
        s[--len] = '\0';
    int cnt = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            cnt++;
        } else if (cnt > 0) {
            if (first)
                first = 0;
            else
                printf(",");
            printf("%d", cnt);
            cnt = 0;
        }
    }
}

void output() { printf("\n"); }

int main() {
    input();
    process();
    output();
    return 0;
}
