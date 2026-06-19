#include <bits/stdc++.h>
using namespace std;

char s[1100];
int  freq[26];

void input() { scanf("%s", s); }

void process() {
    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;
}

void output() {
    for (int i = 0; s[i]; i++)
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return;
        }
    printf("no\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
