#include <bits/stdc++.h>
using namespace std;

int k, n[500005];

void input() {
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        scanf("%d", &n[i]);
}

void process() {
    int xorSum = 0;
    for (int i = 1; i <= k; i++)
        xorSum ^= n[i];
    if (xorSum == 0) {
        printf("lose\n");
        return;
    }
    for (int i = 1; i <= k; i++) {
        int target = n[i] ^ xorSum;
        if (target < n[i]) {
            int take = n[i] - target;
            printf("%d %d\n", take, i);
            n[i] = target;
            break;
        }
    }
    for (int i = 1; i <= k; i++)
        printf("%d%c", n[i], i == k ? '\n' : ' ');
}

int main() {
    input();
    process();
    return 0;
}
