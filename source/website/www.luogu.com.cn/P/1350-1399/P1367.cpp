#include <bits/stdc++.h>
using namespace std;

struct Ant {
    int id, pos, dir, finalPos, finalDir;
};

int         n, t;
vector<Ant> ants;

void input() {
    scanf("%d%d", &n, &t);
    ants.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &ants[i].pos, &ants[i].dir);
        ants[i].id = i;
    }
}

void process() {
    sort(ants.begin(), ants.end(), [](const Ant &a, const Ant &b) { return a.pos < b.pos; });
    vector<pair<int, int>> ghostPairs(n);
    for (int i = 0; i < n; ++i)
        ghostPairs[i] = {ants[i].pos + ants[i].dir * t, i};
    sort(ghostPairs.begin(), ghostPairs.end());
    for (int i = 0; i < n; ++i) {
        ants[i].finalPos = ghostPairs[i].first;
        if ((i > 0 && ghostPairs[i].first == ghostPairs[i - 1].first) || (i < n - 1 && ghostPairs[i].first == ghostPairs[i + 1].first))
            ants[i].finalDir = 0;
        else
            ants[i].finalDir = ants[ghostPairs[i].second].dir;
    }
    sort(ants.begin(), ants.end(), [](const Ant &a, const Ant &b) { return a.id < b.id; });
}

void output() {
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", ants[i].finalPos, ants[i].finalDir);
}

int main() {
    input();
    process();
    output();
    return 0;
}
