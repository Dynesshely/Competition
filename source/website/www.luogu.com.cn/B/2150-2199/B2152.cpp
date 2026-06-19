#include <bits/stdc++.h>
using namespace std;

int         n;
vector<int> digits;

void input() { scanf("%d", &n); }

void process() {
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

void output() {
    for (int i = 0; i < (int)digits.size(); i++) {
        if (i)
            printf(" ");
        printf("%d", digits[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
