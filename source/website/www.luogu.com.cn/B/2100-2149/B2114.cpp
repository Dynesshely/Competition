#include <bits/stdc++.h>
using namespace std;

char s[260];

void input() { scanf("%s", s); }

void process() {}

void output() {
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A')
            printf("T");
        else if (s[i] == 'T')
            printf("A");
        else if (s[i] == 'G')
            printf("C");
        else if (s[i] == 'C')
            printf("G");
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
