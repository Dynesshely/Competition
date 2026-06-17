#include <bits/stdc++.h>
using namespace std;

int         Ca, Cb, N;
vector<int> ops;

struct State {
    int a, b, op, prev;
};

void input() { scanf("%d%d%d", &Ca, &Cb, &N); }

void process() {
    ops.clear();
    int           cols  = Cb + 1;
    int           total = (Ca + 1) * cols;
    vector<bool>  vis(total, false);
    vector<State> states;
    states.reserve(total);
    queue<int> q;

    auto addState = [&](int a, int b, int op, int prev) {
        int id = a * cols + b;
        if (vis[id])
            return;
        vis[id] = true;
        states.push_back({a, b, op, prev});
        q.push(states.size() - 1);
    };

    addState(0, 0, 0, -1);
    int targetIdx = -1;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        int a = states[idx].a, b = states[idx].b;

        if (b == N) {
            targetIdx = idx;
            break;
        }

        addState(Ca, b, 1, idx);
        addState(a, Cb, 2, idx);
        addState(0, b, 3, idx);
        addState(a, 0, 4, idx);

        int pour = min(b, Ca - a);
        if (pour > 0)
            addState(a + pour, b - pour, 5, idx);

        pour = min(a, Cb - b);
        if (pour > 0)
            addState(a - pour, b + pour, 6, idx);
    }

    for (int i = targetIdx; i != 0; i = states[i].prev)
        ops.push_back(states[i].op);
    reverse(ops.begin(), ops.end());
}

void output() {
    printf("%d", (int)ops.size());
    for (int op : ops)
        printf(" %d", op);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        input();
        process();
        output();
    }
    return 0;
}
