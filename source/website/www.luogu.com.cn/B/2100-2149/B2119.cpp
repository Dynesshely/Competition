#include <bits/stdc++.h>
using namespace std;

char s[35];

void input() { scanf("%s", s); }

void process() {
    int len = strlen(s);
    if (len >= 3 && s[len - 1] == 'g' && s[len - 2] == 'n' && s[len - 3] == 'i')
        s[len - 3] = '\0';
    else if (len >= 2 && s[len - 1] == 'y' && s[len - 2] == 'l')
        s[len - 2] = '\0';
    else if (len >= 2 && s[len - 1] == 'r' && s[len - 2] == 'e')
        s[len - 2] = '\0';
}

void output() { printf("%s\n", s); }

int main() {
    input();
    process();
    output();
    return 0;
}
