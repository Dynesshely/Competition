#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int  n;

int parse(int &i) {
    int pos = 0;
    while (i < n) {
        while (i < n && s[i] == ' ')
            ++i;
        if (i >= n || s[i] == ']')
            break;
        if (s[i] == 'F') {
            i += 2;
            while (i < n && s[i] == ' ')
                ++i;
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            pos += num;
        } else if (s[i] == 'B') {
            i += 2;
            while (i < n && s[i] == ' ')
                ++i;
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            pos -= num;
        } else {
            i += 6;
            while (i < n && s[i] == ' ')
                ++i;
            int times = 0;
            while (i < n && isdigit(s[i])) {
                times = times * 10 + (s[i] - '0');
                ++i;
            }
            while (i < n && s[i] == ' ')
                ++i;
            if (i < n)
                ++i;
            int inner = parse(i);
            while (i < n && s[i] == ' ')
                ++i;
            if (i < n)
                ++i;
            pos += times * inner;
        }
    }
    return pos;
}

int main() {
    fgets(s, sizeof(s), stdin);
    n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r'))
        s[--n] = '\0';
    int i   = 0;
    int ans = parse(i);
    printf("%d\n", abs(ans));
    return 0;
}
