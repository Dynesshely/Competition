#include <bits/stdc++.h>
using namespace std;

int main() {
    int p1, p2, p3;
    scanf("%d%d%d", &p1, &p2, &p3);
    char s[105];
    scanf("%s", s);
    putchar(s[0]);
    for (int i = 1; s[i]; ++i) {
        if (s[i] == '-' && s[i + 1]) {
            char l = s[i - 1], r = s[i + 1];
            if (isdigit(l) && isdigit(r) && l < r) {
                if (p3 == 1)
                    for (char ch = l + 1; ch < r; ++ch)
                        for (int k = 0; k < p2; ++k) putchar(p1 == 3 ? '*' : ch);
                else
                    for (char ch = r - 1; ch > l; --ch)
                        for (int k = 0; k < p2; ++k) putchar(p1 == 3 ? '*' : ch);
                continue;
            } else if (islower(l) && islower(r) && l < r) {
                if (p3 == 1)
                    for (char ch = l + 1; ch < r; ++ch)
                        for (int k = 0; k < p2; ++k) putchar(p1 == 3 ? '*' : (p1 == 2 ? toupper(ch) : ch));
                else
                    for (char ch = r - 1; ch > l; --ch)
                        for (int k = 0; k < p2; ++k) putchar(p1 == 3 ? '*' : (p1 == 2 ? toupper(ch) : ch));
                continue;
            }
        }
        putchar(s[i]);
    }
    putchar('\n');
    return 0;
}
