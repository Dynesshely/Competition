#include <bits/stdc++.h>
using namespace std;

char s[55];
int  len;

void input() {
    scanf("%s", s);
    len = strlen(s);
}

void process() {
    for (int i = 0; i < len; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        else
            s[i] = s[i] - 'a' + 'A';
    for (int i = 0; i < len / 2; i++) {
        char t         = s[i];
        s[i]           = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
    for (int i = 0; i < len; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + 3) % 26 + 'a';
        else
            s[i] = (s[i] - 'A' + 3) % 26 + 'A';
}

void output() { printf("%s\n", s); }

int main() {
    input();
    process();
    output();
    return 0;
}
