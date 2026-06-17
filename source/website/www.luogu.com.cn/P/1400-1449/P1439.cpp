#include <bits/stdc++.h>
using namespace std;

int n;
int p1[100005], p2[100005], pos[100005], arr[100005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p1[i]);
        pos[p1[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p2[i]);
        arr[i] = pos[p2[i]];
    }
}

void process() {
    vector<int> tail;
    for (int i = 1; i <= n; ++i) {
        int  x  = arr[i];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x;
    }
    printf("%d\n", (int)tail.size());
}

int main() {
    input();
    process();
    return 0;
}
