#include <bits/stdc++.h>
using namespace std;

int  a, b, res;
char op;
bool err;
char msg[100];

void input() { scanf("%d%d %c", &a, &b, &op); }

void process() {
    err = false;
    switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0) {
                err = true;
                sprintf(msg, "Divided by zero!");
            } else {
                res = a / b;
            }
            break;
        default:
            err = true;
            sprintf(msg, "Invalid operator!");
    }
}

void output() {
    if (err)
        printf("%s\n", msg);
    else
        printf("%d\n", res);
}

int main() {
    input();
    process();
    output();
    return 0;
}
