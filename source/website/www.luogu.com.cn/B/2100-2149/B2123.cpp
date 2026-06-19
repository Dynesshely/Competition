#include <bits/stdc++.h>
using namespace std;

char s[1005];

void input() { scanf("%s", s); }

void process() {
    int len = strlen(s);
    int cnt = 1;
    for (int i = 1; i <= len; i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else {
            printf("%d%c", cnt, s[i - 1]);
            cnt = 1;
        }
    }
}

int main() {
    input();
    process();
    return 0;
}
