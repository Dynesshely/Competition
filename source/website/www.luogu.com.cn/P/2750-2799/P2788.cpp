#include <bits/stdc++.h>
using namespace std;

char s[60005];
int  ans;

void input() { scanf("%s", s); }

void process() {
    int i = 0, sign = 1;
    while (s[i]) {
        if (s[i] == '+')
            sign = 1, ++i;
        else if (s[i] == '-')
            sign = -1, ++i;
        else {
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i++] - '0');
            ans += sign * num;
        }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
