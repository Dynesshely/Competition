#include <bits/stdc++.h>
using namespace std;

int  x;
bool d3, d5, d7;

void input() { scanf("%d", &x); }

void process() {
    d3 = x % 3 == 0;
    d5 = x % 5 == 0;
    d7 = x % 7 == 0;
}

void output() {
    if (d3 && d5 && d7)
        printf("3 5 7\n");
    else if (d3 && d5)
        printf("3 5\n");
    else if (d3 && d7)
        printf("3 7\n");
    else if (d5 && d7)
        printf("5 7\n");
    else if (d3)
        printf("3\n");
    else if (d5)
        printf("5\n");
    else if (d7)
        printf("7\n");
    else
        printf("n\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
