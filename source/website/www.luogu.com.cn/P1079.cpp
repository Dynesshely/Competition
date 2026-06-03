#include <bits/stdc++.h>
using namespace std;

int main() {
    char key[105], cipher[1005];
    scanf("%s%s", key, cipher);
    int klen = strlen(key);
    for (int i = 0; cipher[i]; ++i) {
        int kn = (key[i % klen] >= 'a') ? key[i % klen] - 'a' : key[i % klen] - 'A';
        int cn = (cipher[i] >= 'a') ? cipher[i] - 'a' : cipher[i] - 'A';
        int pn = (cn - kn + 26) % 26;
        putchar((cipher[i] >= 'a' ? 'a' : 'A') + pn);
    }
    putchar('\n');
    return 0;
}
