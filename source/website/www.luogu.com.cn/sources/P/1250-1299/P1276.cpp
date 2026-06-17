#include <bits/stdc++.h>
using namespace std;

int         l, n;
vector<int> state;

void output(int remain, int cut) { printf("%d\n%d\n", remain, cut); }

void input() {
    scanf("%d%d", &l, &n);
    state.resize(l + 1, 1);
}

void process() {
    int remain = 0, cut = 0;
    for (int i = 0; i < n; i++) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 0) {
            for (int j = a; j <= b; j++) {
                if (state[j] == 2)
                    cut++;
                if (state[j] == 1 || state[j] == 2)
                    state[j] = 0;
            }
        } else {
            for (int j = a; j <= b; j++)
                if (state[j] == 0)
                    state[j] = 2;
        }
    }
    for (int i = 0; i <= l; i++)
        if (state[i] == 2)
            remain++;
    output(remain, cut);
}

int main() {
    input();
    process();
    return 0;
}
