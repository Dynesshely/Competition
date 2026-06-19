#include <bits/stdc++.h>
using namespace std;

int  n;
int  maxScore = -1;
char maxName[25];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int  score;
        char name[25];
        scanf("%d%s", &score, name);
        if (score > maxScore) {
            maxScore = score;
            strcpy(maxName, name);
        }
    }
}

int main() {
    input();
    printf("%s\n", maxName);
    return 0;
}
