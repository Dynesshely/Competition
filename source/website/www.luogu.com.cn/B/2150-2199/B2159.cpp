#include <bits/stdc++.h>
using namespace std;

int  n;
char name[25][25];
int  sc[25];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s%d", name[i], &sc[i]);
}

void process() {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (sc[j] < sc[j + 1] || (sc[j] == sc[j + 1] && strcmp(name[j], name[j + 1]) > 0)) {
                swap(sc[j], sc[j + 1]);
                char tmp[25];
                strcpy(tmp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tmp);
            }
}

void output() {
    for (int i = 0; i < n; i++)
        printf("%s %d\n", name[i], sc[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
