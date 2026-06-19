#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    char s1[15], s2[15];
    for (int i = 0; i < n; i++) {
        scanf("%s%s", s1, s2);
        if (strcmp(s1, s2) == 0)
            printf("Tie\n");
        else if ((strcmp(s1, "Rock") == 0 && strcmp(s2, "Scissors") == 0) || (strcmp(s1, "Scissors") == 0 && strcmp(s2, "Paper") == 0) || (strcmp(s1, "Paper") == 0 && strcmp(s2, "Rock") == 0))
            printf("Player1\n");
        else
            printf("Player2\n");
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
