#include <bits/stdc++.h>
using namespace std;

char s[510], word[510], ans[510];

void input() { cin.getline(s, 505); }

void process() {
    int   maxLen = 0;
    char *token  = strtok(s, " .");
    while (token != NULL) {
        int curLen = strlen(token);
        if (curLen > maxLen) {
            maxLen = curLen;
            strcpy(ans, token);
        }
        token = strtok(NULL, " .");
    }
}

void output() { printf("%s\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
