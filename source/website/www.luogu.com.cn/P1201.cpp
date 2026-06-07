#include <bits/stdc++.h>
using namespace std;

int                        np;
char                       names[15][20];
int                        net[15];
unordered_map<string, int> idx;

void input() {
    scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        scanf("%s", names[i]);
        idx[names[i]] = i;
    }
}

void process() {
    char name[20], recv[20];
    int  money, ng;
    for (int i = 0; i < np; ++i) {
        scanf("%s", name);
        scanf("%d%d", &money, &ng);
        if (ng == 0)
            continue;
        int each = money / ng;
        int give = each * ng;
        net[idx[name]] -= give;
        for (int j = 0; j < ng; ++j) {
            scanf("%s", recv);
            net[idx[recv]] += each;
        }
    }
}

void output() {
    for (int i = 0; i < np; ++i)
        printf("%s %d\n", names[i], net[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
