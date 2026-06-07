#include <bits/stdc++.h>
using namespace std;

int                   n;
stack<pair<int, int>> s;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 0) {
            int x;
            scanf("%d", &x);
            if (s.empty())
                s.push({x, x});
            else
                s.push({x, max(x, s.top().second)});
        } else if (op == 1) {
            if (!s.empty())
                s.pop();
        } else {
            if (s.empty())
                printf("0\n");
            else
                printf("%d\n", s.top().second);
        }
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
