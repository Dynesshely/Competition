#include <bits/stdc++.h>
using namespace std;

char s[10010];

void input() { fgets(s, 10010, stdin); }

void process() {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' - 1 + 26) % 26 + 'A';
    }
}

void output() { printf("%s", s); }

int main() {
    input();
    process();
    output();
    return 0;
}
