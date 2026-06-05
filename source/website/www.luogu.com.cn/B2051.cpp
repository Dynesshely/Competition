#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
