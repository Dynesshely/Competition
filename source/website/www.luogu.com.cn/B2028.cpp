#include <bits/stdc++.h>
using namespace std;

char s[4];

void input() { scanf("%s", s); }

void process() { reverse(s, s + 3); }

void output() { printf("%s\n", s); }

int main() {
    input();
    process();
    output();
    return 0;
}
