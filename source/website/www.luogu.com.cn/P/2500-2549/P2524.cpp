#include <bits/stdc++.h>
using namespace std;

int  n, p[15], target[15], ans;
char s[15];

void input() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++)
        target[i] = s[i] - '0';
}

void process() {
    for (int i = 0; i < n; i++)
        p[i] = i + 1;
    ans = 1;
    while (true) {
        bool match = true;
        for (int i = 0; i < n; i++)
            if (p[i] != target[i]) {
                match = false;
                break;
            }
        if (match)
            break;
        next_permutation(p, p + n);
        ans++;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
