#include <bits/stdc++.h>
using namespace std;

int  n, sum, maxLen, target, need;
int  a[66];
bool used[66];

bool dfs(int cnt, int cur, int start) {
    if (cnt == need)
        return true;
    if (cur == target)
        return dfs(cnt + 1, 0, 0);
    int last = -1;
    for (int i = start; i < n; i++) {
        if (used[i] || a[i] == last || cur + a[i] > target)
            continue;
        used[i] = true;
        last    = a[i];
        if (dfs(cnt, cur + a[i], i + 1))
            return true;
        used[i] = false;
        if (cur == 0 || cur + a[i] == target)
            return false;
    }
    return false;
}

void input() {
    scanf("%d", &n);
    sum    = 0;
    maxLen = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i] > maxLen)
            maxLen = a[i];
    }
}

void process() { sort(a, a + n, greater<int>()); }

void output() {
    for (int len = maxLen; len <= sum / 2; len++) {
        if (sum % len == 0) {
            target = len;
            need   = sum / len;
            fill(used, used + n, false);
            if (dfs(0, 0, 0)) {
                printf("%d\n", len);
                return;
            }
        }
    }
    printf("%d\n", sum);
}

int main() {
    input();
    process();
    output();
    return 0;
}
