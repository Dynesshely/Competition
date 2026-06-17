#include <bits/stdc++.h>
using namespace std;

int  n;
char s[710];
int  ans;

void input() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++)
        s[i + n] = s[i];
}

void process() {
    ans = 0;
    for (int i = 0; i < n; i++) {
        char col   = 'w';
        int  right = 0;
        for (int j = i; j < i + n; j++) {
            if (s[j] == 'w')
                right++;
            else if (col == 'w')
                col = s[j], right++;
            else if (s[j] == col)
                right++;
            else
                break;
        }
        col      = 'w';
        int left = 0;
        for (int j = i + n - 1; j >= i; j--) {
            if (s[j] == 'w')
                left++;
            else if (col == 'w')
                col = s[j], left++;
            else if (s[j] == col)
                left++;
            else
                break;
        }
        int total = left + right;
        if (total > n)
            total = n;
        if (total > ans)
            ans = total;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
