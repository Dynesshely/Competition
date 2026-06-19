#include <bits/stdc++.h>
using namespace std;

char s[205], a[105], b[105], w[105];

void input() {
    fgets(s, sizeof(s), stdin);
    int sl = strlen(s);
    while (sl > 0 && (s[sl - 1] == '\n' || s[sl - 1] == '\r'))
        s[--sl] = '\0';
    scanf("%s", a);
    scanf("%s", b);
}

void process() {
    int len = strlen(s), wi = 0, first = 1;
    for (int i = 0; i <= len; i++)
        if (s[i] == ' ' || s[i] == '\0') {
            w[wi]     = '\0';
            int match = (strcmp(w, a) == 0);
            if (!first)
                printf(" ");
            printf("%s", match ? b : w);
            first = 0;
            wi    = 0;
        } else
            w[wi++] = s[i];
    printf("\n");
}

int main() {
    input();
    process();
    return 0;
}
