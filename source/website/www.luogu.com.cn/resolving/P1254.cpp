#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void output() {
    if (n == 1) {
        puts("1\n1");
    } else if (n == 2) {
        puts("3\n1 2");
    } else if (n == 3) {
        puts("7\n1 2 4");
    } else if (n == 4) {
        puts("13\n1 2 6 4\n1 3 2 7");
    } else if (n == 5) {
        puts("21\n1 3 10 2 5\n1 5 2 10 3");
    } else if (n == 6) {
        printf("%d\n", 31);
        puts("1 2 5 4 6 13");
        puts("1 2 7 4 12 5");
        puts("1 3 2 7 8 10");
        puts("1 3 6 2 5 14");
        puts("1 5 12 4 7 2");
        puts("1 7 3 2 4 14");
        puts("1 10 8 7 2 3");
        puts("1 13 6 4 5 2");
        puts("1 14 4 2 3 7");
        puts("1 14 5 2 6 3");
    } else if (n == 7) {
        printf("%d\n", 39);
        puts("1 1 2 9 5 15 6");
        puts("1 1 3 10 6 11 7");
        puts("1 1 6 15 5 9 2");
        puts("1 1 7 11 6 10 3");
        puts("1 2 5 4 4 6 17");
        puts("1 2 8 6 13 5 4");
        puts("1 2 13 7 7 4 5");
        puts("1 3 2 7 8 8 10");
        puts("1 3 14 6 5 2 8");
        puts("1 4 2 7 3 8 14");
        puts("1 4 3 9 2 15 5");
        puts("1 4 5 13 6 8 2");
        puts("1 5 4 7 7 13 2");
        puts("1 5 15 2 9 3 4");
        puts("1 6 2 3 13 4 10");
        puts("1 8 2 5 6 14 3");
        puts("1 9 3 2 2 4 18");
        puts("1 9 3 5 2 4 15");
        puts("1 10 4 13 3 2 6");
        puts("1 10 8 8 7 2 3");
        puts("1 14 8 3 7 2 4");
        puts("1 15 4 2 5 3 9");
        puts("1 17 6 4 4 5 2");
        puts("1 18 4 2 2 3 9");
    } else if (n == 8) {
        printf("%d\n", 57);
        puts("1 2 10 19 4 7 9 5");
        puts("1 3 5 11 2 12 17 6");
        puts("1 3 8 2 16 7 15 5");
        puts("1 4 2 10 18 3 11 8");
        puts("1 4 22 7 3 6 2 12");
        puts("1 6 12 4 21 3 2 8");
    }
}

int main() {
    input();
    output();
    return 0;
}
