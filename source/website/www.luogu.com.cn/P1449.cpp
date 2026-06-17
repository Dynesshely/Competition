#include <bits/stdc++.h>
using namespace std;

char s[55];
int  stk[55], top;

void input() { scanf("%s", s); }

void process() {
    int num = 0;
    for (int i = 0; s[i] != '@'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9')
            num = num * 10 + (c - '0');
        else if (c == '.') {
            stk[++top] = num;
            num        = 0;
        } else {
            int b = stk[top--];
            int a = stk[top--];
            if (c == '+')
                stk[++top] = a + b;
            else if (c == '-')
                stk[++top] = a - b;
            else if (c == '*')
                stk[++top] = a * b;
            else
                stk[++top] = a / b;
        }
    }
}

void output() { printf("%d\n", stk[top]); }

int main() {
    input();
    process();
    output();
    return 0;
}
