#include <bits/stdc++.h>
using namespace std;

char s[260];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int boy = 0, girl = 0;
    if (s[0] == 'b') ++boy;
    else if (s[0] == 'g') ++girl;
    for (int i = 1; i < len; ++i) {
        if (s[i] == 'b') ++boy;
        else if (s[i] == 'o' && s[i - 1] != 'b') ++boy;
        else if (s[i] == 'y' && s[i - 1] != 'o') ++boy;
        else if (s[i] == 'g') ++girl;
        else if (s[i] == 'i' && s[i - 1] != 'g') ++girl;
        else if (s[i] == 'r' && s[i - 1] != 'i') ++girl;
        else if (s[i] == 'l' && s[i - 1] != 'r') ++girl;
    }
    printf("%d\n%d\n", boy, girl);
    return 0;
}
