#include <bits/stdc++.h>
using namespace std;

char mapE2O[26], mapO2E[26];
bool inOrig[26];

int main() {
    char enc[105], orig[105], target[105];
    scanf("%s%s%s", enc, orig, target);
    int len = strlen(enc);
    memset(mapE2O, -1, sizeof(mapE2O));
    memset(mapO2E, -1, sizeof(mapO2E));
    for (int i = 0; i < len; ++i) {
        int e = enc[i] - 'A', o = orig[i] - 'A';
        if (mapE2O[e] != -1 && mapE2O[e] != o) { printf("Failed\n"); return 0; }
        if (mapO2E[o] != -1 && mapO2E[o] != e) { printf("Failed\n"); return 0; }
        mapE2O[e] = o;
        mapO2E[o] = e;
        inOrig[o] = true;
    }
    for (int i = 0; i < 26; ++i)
        if (!inOrig[i]) { printf("Failed\n"); return 0; }
    for (int i = 0; target[i]; ++i) {
        int e = target[i] - 'A';
        putchar(mapE2O[e] + 'A');
    }
    putchar('\n');
    return 0;
}
