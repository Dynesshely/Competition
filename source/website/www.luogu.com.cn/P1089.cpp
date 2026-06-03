#include <bits/stdc++.h>
using namespace std;

int main() {
    int cash = 0, saved = 0;
    for (int i = 1; i <= 12; ++i) {
        int budget; scanf("%d", &budget);
        cash += 300;
        if (cash < budget) { printf("-%d\n", i); return 0; }
        cash -= budget;
        int s = cash / 100 * 100; saved += s; cash -= s;
    }
    printf("%d\n", cash + saved * 6 / 5);
    return 0;
}
