#include <bits/stdc++.h>
using namespace std;

typedef __int128 i128;

void print128(i128 x) {
    if (x >= 10)
        print128(x / 10);
    putchar('0' + (int)(x % 10));
}

int k, n;

void input() { scanf("%d%d", &k, &n); }

void process() {
    i128                            a0 = 1, b0 = k, c0 = (i128)k * (k + 1);
    set<tuple<i128, i128, i128>>    seen;
    vector<tuple<i128, i128, i128>> cur, nxt;
    auto                            norm = [](i128 &x, i128 &y, i128 &z) {
        if (x > y)
            swap(x, y);
        if (y > z)
            swap(y, z);
        if (x > y)
            swap(x, y);
    };
    norm(a0, b0, c0);
    cur.push_back({a0, b0, c0});
    seen.insert({a0, b0, c0});
    int cnt = 0;
    while (cnt < n && !cur.empty()) {
        nxt.clear();
        for (auto [a, b, c] : cur) {
            if (cnt >= n)
                break;
            print128(a);
            putchar(' ');
            print128(b);
            putchar(' ');
            print128(c);
            putchar('\n');
            ++cnt;
            auto tryPush = [&](i128 na, i128 nb, i128 nc) {
                if (na <= 0 || nb <= 0 || nc <= 0)
                    return;
                norm(na, nb, nc);
                if (seen.count({na, nb, nc}))
                    return;
                seen.insert({na, nb, nc});
                nxt.push_back({na, nb, nc});
            };
            tryPush((i128)k * (b + c) - a, b, c);
            tryPush(a, (i128)k * (a + c) - b, c);
            tryPush(a, b, (i128)k * (a + b) - c);
        }
        cur.swap(nxt);
    }
}

int main() {
    input();
    process();
    return 0;
}
