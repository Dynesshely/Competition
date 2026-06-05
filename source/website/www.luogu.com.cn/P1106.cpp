#include <bits/stdc++.h>
using namespace std;

char n[255];
int  k, len;
char stk[255];
int  top;
char ans[255];
int  ansLen;

void input() {
    scanf("%s", n);
    scanf("%d", &k);
}

void process() {
    len = strlen(n);
    top = 0;
    for (int i = 0; i < len; i++) {
        while (top > 0 && k > 0 && stk[top - 1] > n[i]) {
            top--;
            k--;
        }
        stk[top++] = n[i];
    }
    top -= k;
    ansLen           = 0;
    bool leadingZero = true;
    for (int i = 0; i < top; i++) {
        if (leadingZero && stk[i] == '0')
            continue;
        leadingZero   = false;
        ans[ansLen++] = stk[i];
    }
    if (ansLen == 0)
        ans[ansLen++] = '0';
    ans[ansLen] = '\0';
}

void output() { printf("%s", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
