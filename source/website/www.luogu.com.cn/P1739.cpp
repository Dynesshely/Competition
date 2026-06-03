#include <bits/stdc++.h>
using namespace std;

char expr[260];
int len;
bool ok;

void input() {
    scanf("%s", expr);
    len = strlen(expr);
}

void process() {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') {
            cnt++;
        } else if (expr[i] == ')') {
            cnt--;
            if (cnt < 0) {
                ok = false;
                return;
            }
        }
    }
    ok = (cnt == 0);
}

void output() {
    if (ok) printf("YES\n");
    else printf("NO\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
