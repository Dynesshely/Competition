#include <bits/stdc++.h>
using namespace std;

int  l, r, L, R, k;
char cnt[10000005];

void input() { scanf("%d%d%d%d%d", &l, &r, &L, &R, &k); }

void process() {
    for (int i = L; i <= R; ++i)
        cnt[i] = 0;
    for (int b = l; b <= r; ++b) {
        for (int fst = 1; fst < b; ++fst) {
            if (fst >= L && fst <= R)
                cnt[fst]++;
            for (int snd = 0; snd < b; ++snd) {
                if (snd == fst)
                    continue;
                long long cur = fst;
                cur           = cur * b + snd;
                int prev      = snd;
                while (cur <= R) {
                    if (cur >= L)
                        cnt[cur]++;
                    long long nxt = cur * b + (prev == fst ? snd : fst);
                    prev          = (prev == fst ? snd : fst);
                    cur           = nxt;
                }
            }
        }
    }
}

void output() {
    for (int i = L; i <= R; ++i)
        if (cnt[i] >= k)
            printf("%d\n", i);
}

int main() {
    input();
    process();
    output();
    return 0;
}
