#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int cnt = (a < 60) + (b < 60) + (c < 60);
    printf("%d\n", cnt == 1 ? 1 : 0);
    return 0;
}
