#include <bits/stdc++.h>
using namespace std;

int a, b;

void input() { scanf("%d%d", &a, &b); }

int process() {
    int firstOdd = a;
    if (firstOdd % 2 == 0)
        firstOdd++;
    int lastOdd = b;
    if (lastOdd % 2 == 0)
        lastOdd--;
    int oddCnt = 0;
    if (firstOdd <= b)
        oddCnt = (lastOdd - firstOdd) / 2 + 1;

    int r         = ((a % 4) + 4) % 4;
    int firstFour = a;
    if (r != 0)
        firstFour += (4 - r);
    int fourCnt = 0;
    if (firstFour <= b) {
        int lastFour = b - ((b % 4 + 4) % 4);
        fourCnt      = (lastFour - firstFour) / 4 + 1;
    }

    return oddCnt + fourCnt;
}

void output() { printf("%d\n", process()); }

int main() {
    input();
    output();
    return 0;
}
