#include <bits/stdc++.h>
using namespace std;

int n, h[10010];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
}

int process() {
    int ans = 0;
    bool down = false;
    for (int i = 1; i < n; i++) {
        if (h[i] < h[i - 1])
            down = true;
        else if (h[i] > h[i - 1] && down) {
            ans++;
            down = false;
        }
    }
    return ans;
}

void output(int ans) {
    printf("%d\n", ans);
}

int main() {
    input();
    output(process());
    return 0;
}
