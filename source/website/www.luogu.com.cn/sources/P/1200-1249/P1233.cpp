#include <bits/stdc++.h>
using namespace std;

struct Stick {
    int l, w;
};

bool cmp(const Stick &a, const Stick &b) {
    if (a.l != b.l)
        return a.l > b.l;
    return a.w > b.w;
}

int   n;
Stick sticks[5005];
int   w[5005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &sticks[i].l, &sticks[i].w);
}

void process() {
    sort(sticks, sticks + n, cmp);
    for (int i = 0; i < n; i++)
        w[i] = sticks[i].w;
}

void output() {
    vector<int> tails;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), w[i]);
        if (it == tails.end())
            tails.push_back(w[i]);
        else
            *it = w[i];
    }
    printf("%d\n", (int)tails.size());
}

int main() {
    input();
    process();
    output();
    return 0;
}
