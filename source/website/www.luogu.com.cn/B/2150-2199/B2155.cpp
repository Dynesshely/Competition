#include <bits/stdc++.h>
using namespace std;

char s[25];
bool ok = true;

void input() { scanf("%s", s); }

void process() {
    int len = strlen(s);
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_')) {
        ok = false;
        return;
    }
    for (int i = 1; i < len; i++)
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')) {
            ok = false;
            return;
        }
}

void output() { printf("%s\n", ok ? "yes" : "no"); }

int main() {
    input();
    process();
    output();
    return 0;
}
