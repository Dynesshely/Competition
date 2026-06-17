#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    priority_queue<int>                            left;
    priority_queue<int, vector<int>, greater<int>> right;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        if (i % 2 == 1)
            printf("%d\n", left.top());
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
