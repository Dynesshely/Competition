#include <bits/stdc++.h>
using namespace std;

char s[260];
int  cnt;

void input() { fgets(s, 260, stdin); }

void process() {
    for (int i = 0; s[i]; i++)
        if (s[i] >= '0' && s[i] <= '9')
            cnt++;
}

void output() { printf("%d\n", cnt); }

int main() {
    input();
    process();
    output();
    return 0;
}
