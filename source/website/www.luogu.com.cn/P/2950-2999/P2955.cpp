#include <bits/stdc++.h>
using namespace std;

int  n;
char s[65];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int len = strlen(s);
        if ((s[len - 1] - '0') & 1)
            puts("odd");
        else
            puts("even");
    }
    return 0;
}
