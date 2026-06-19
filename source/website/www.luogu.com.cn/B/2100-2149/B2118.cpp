#include <bits/stdc++.h>
using namespace std;

char s1[35], s2[35];

void input() { scanf("%s%s", s1, s2); }

void process() {
    if (strstr(s2, s1))
        printf("%s is substring of %s\n", s1, s2);
    else if (strstr(s1, s2))
        printf("%s is substring of %s\n", s2, s1);
    else
        printf("No substring\n");
}

int main() {
    input();
    process();
    return 0;
}
