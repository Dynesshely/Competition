#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int ns[10] = {5, 5, 10, 10, 10, 10, 80, 80, 100, 100};
    int nt[101];
    for (int i = 0; i < 10; ++i) {
        memset(nt, 0, sizeof(int) * 101);
        ostringstream os1, os2;
        os1 << "P1003/for" << i + 1 << ".in";
        os2 << "P1003/for" << i + 1 << ".ans";
        freopen(os1.str().c_str(), "w", stdout);
        printf("%d\n", ns[i]);
        for (int j = 1; j <= ns[i]; ++j) {
            nt[j] = rand() % 100;
            printf("%d ", nt[j]);
        }
        freopen(os2.str().c_str(), "w", stdout);
        for (int j = 1; j <= ns[i]; ++j) {
            printf("%d ", nt[j]);
        }
    }
    return 0;
}