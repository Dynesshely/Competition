#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id, score, strength;
};

int    n, r, q;
Player p[200005];
Player win[100005], lose[100005];

void input() {
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 0; i < 2 * n; i++) {
        p[i].id = i + 1;
        scanf("%d", &p[i].score);
    }
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &p[i].strength);
}

void process() {
    sort(p, p + 2 * n, [](const Player &a, const Player &b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.id < b.id;
    });
    for (int round = 0; round < r; round++) {
        int wi = 0, li = 0;
        for (int i = 0; i < n; i++) {
            int a = 2 * i, b = 2 * i + 1;
            if (p[a].strength > p[b].strength) {
                p[a].score++;
                win[wi++]  = p[a];
                lose[li++] = p[b];
            } else {
                p[b].score++;
                win[wi++]  = p[b];
                lose[li++] = p[a];
            }
        }
        int i = 0, j = 0, k = 0;
        while (i < n && j < n) {
            if (win[i].score > lose[j].score || (win[i].score == lose[j].score && win[i].id < lose[j].id))
                p[k++] = win[i++];
            else
                p[k++] = lose[j++];
        }
        while (i < n)
            p[k++] = win[i++];
        while (j < n)
            p[k++] = lose[j++];
    }
}

void output() { printf("%d\n", p[q - 1].id); }

int main() {
    input();
    process();
    output();
    return 0;
}
