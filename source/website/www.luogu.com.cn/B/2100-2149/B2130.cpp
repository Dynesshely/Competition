#include <bits/stdc++.h>
using namespace std;

char s[1005];

void input() { fgets(s, sizeof(s), stdin); }

void process() {
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
    int idx = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] != ' ')
            s[idx++] = s[i];
    s[idx] = '\0';
    int  a, b;
    char op;
    int  pos = -1;
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i])) {
            pos = i;
            op  = s[i];
            break;
        }
    s[pos] = '\0';
    a      = atoi(s);
    b      = atoi(s + pos + 1);
    int res;
    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else
        res = a % b;
    printf("%d\n", res);
}

int main() {
    input();
    process();
    return 0;
}
