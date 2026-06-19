#include <bits/stdc++.h>
using namespace std;

int xA, yA, xB, yB, xC, yC;

int main() {
    scanf("%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC);
    int area = abs(xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB));
    printf("%d\n", area / 2);
    return 0;
}
