#include <bits/stdc++.h>
using namespace std;

char s[20005];
char cur[105];
char longest[105], shortest[105];
int  maxLen, minLen = 105;

void input() { fgets(s, 20005, stdin); }

void process() {
    int len = strlen(s);
    if (s[len - 1] == '\n')
        s[--len] = '\0';
    int idx = 0;
    for (int i = 0; i <= len; i++) {
        if (isalpha(s[i])) {
            cur[idx++] = s[i];
        } else if (idx > 0) {
            cur[idx] = '\0';
            if (idx > maxLen) {
                maxLen = idx;
                strcpy(longest, cur);
            }
            if (idx < minLen) {
                minLen = idx;
                strcpy(shortest, cur);
            }
            idx = 0;
        }
    }
}

void output() { printf("%s\n%s\n", longest, shortest); }

int main() {
    input();
    process();
    output();
    return 0;
}
