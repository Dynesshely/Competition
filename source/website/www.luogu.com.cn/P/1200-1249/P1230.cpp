#include <bits/stdc++.h>
using namespace std;

struct Game {
    int deadline, penalty;
};

bool cmp(const Game &a, const Game &b) { return a.penalty > b.penalty; }

int  m, n;
Game games[505];
bool used[505];

void input() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &games[i].deadline);
    for (int i = 0; i < n; i++)
        scanf("%d", &games[i].penalty);
}

void process() {
    sort(games, games + n, cmp);
    for (int i = 0; i < n; i++) {
        int pos = games[i].deadline;
        while (pos >= 1 && used[pos])
            pos--;
        if (pos >= 1)
            used[pos] = true;
        else
            m -= games[i].penalty;
    }
}

void output() { printf("%d\n", m); }

int main() {
    input();
    process();
    output();
    return 0;
}
