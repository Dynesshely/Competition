#include <bits/stdc++.h>
using namespace std;

int sx, sy, ex, ey, t, ans;
int cnt[4];

void input() {
    scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &t);
    for (int i = 0; i < t; ++i) {
        char dir[2];
        scanf("%s", dir);
        if (dir[0] == 'E')
            ++cnt[0];
        else if (dir[0] == 'S')
            ++cnt[1];
        else if (dir[0] == 'W')
            ++cnt[2];
        else
            ++cnt[3];
    }
}

void process() {
    int dx = ex - sx, dy = ey - sy;
    if ((dx > 0 && cnt[0] < dx) || (dx < 0 && cnt[2] < -dx) || (dy > 0 && cnt[3] < dy) || (dy < 0 && cnt[1] < -dy))
        ans = -1;
    else
        ans = abs(dx) + abs(dy);
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
