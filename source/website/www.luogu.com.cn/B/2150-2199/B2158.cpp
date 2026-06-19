#include <bits/stdc++.h>
using namespace std;

int    n, k;
int    id[105];
double sc[105];

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%lf", &id[i], &sc[i]);
}

void process() {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (sc[j] < sc[j + 1]) {
                swap(sc[j], sc[j + 1]);
                swap(id[j], id[j + 1]);
            }
}

void output() { printf("%d %g\n", id[k - 1], sc[k - 1]); }

int main() {
    input();
    process();
    output();
    return 0;
}
