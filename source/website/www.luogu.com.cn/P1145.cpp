#include <bits/stdc++.h>
using namespace std;

int k;

bool check(int m) {
    int         n = 2 * k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = i;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int kill = (cur + m - 1) % n;
        if (arr[kill] < k)
            return false;
        arr.erase(arr.begin() + kill);
        --n;
        cur = kill % n;
    }
    return true;
}

int process() {
    for (int m = 2;; ++m)
        if (check(m))
            return m;
}

void input() { scanf("%d", &k); }

void output() { printf("%d\n", process()); }

int main() {
    input();
    output();
    return 0;
}
