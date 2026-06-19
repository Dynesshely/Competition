#include <bits/stdc++.h>
using namespace std;

int  k;
char s[1005];

void input() { scanf("%d%s", &k, s); }

void process() {
    int len = strlen(s);
    int cnt = 1;
    if (cnt >= k) {
        printf("%c\n", s[0]);
        return;
    }
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 1;
        if (cnt >= k) {
            printf("%c\n", s[i]);
            return;
        }
    }
    printf("No\n");
}

int main() {
    input();
    process();
    return 0;
}
