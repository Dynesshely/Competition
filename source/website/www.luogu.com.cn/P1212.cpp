#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int w, h;
};

int  bestArea;
bool bestHt[101];

void record(int w, int h) {
    int area = w * h;
    if (area < bestArea || bestArea == 0) {
        bestArea = area;
        memset(bestHt, 0, sizeof(bestHt));
    }
    if (area == bestArea)
        bestHt[min(w, h)] = true;
}

void check(Rect *r) {
    Rect big;

    big.w = 0;
    big.h = 0;
    for (int i = 0; i < 4; i++) {
        big.w += r[i].w;
        big.h = max(big.h, r[i].h);
    }
    record(big.w, big.h);

    big.w = 0;
    big.h = 0;
    for (int i = 0; i < 3; i++) {
        big.w += r[i].w;
        big.h = max(big.h, r[i].h);
    }
    big.h += r[3].h;
    big.w = max(big.w, r[3].w);
    record(big.w, big.h);

    big.w = r[0].w + r[1].w;
    big.h = max(r[0].h, r[1].h);
    big.h += r[2].h;
    big.w = max(big.w, r[2].w);
    big.w += r[3].w;
    big.h = max(big.h, r[3].h);
    record(big.w, big.h);

    big.w = r[0].w + r[1].w;
    big.h = max(r[0].h, r[1].h);
    big.w += max(r[2].w, r[3].w);
    big.h = max(big.h, r[2].h + r[3].h);
    record(big.w, big.h);

    big.h = max(r[0].h + r[2].h, r[1].h + r[3].h);
    big.w = r[0].w + r[1].w;
    if (r[0].h < r[1].h)
        big.w = max(big.w, r[2].w + r[1].w);
    if (r[0].h + r[2].h > r[1].h)
        big.w = max(big.w, r[2].w + r[3].w);
    if (r[1].h < r[0].h)
        big.w = max(big.w, r[0].w + r[3].w);
    big.w = max(big.w, r[2].w);
    big.w = max(big.w, r[3].w);
    record(big.w, big.h);
}

void dfsRotate(Rect *r, int n) {
    if (n == 4) {
        check(r);
        return;
    }
    dfsRotate(r, n + 1);
    swap(r[n].w, r[n].h);
    dfsRotate(r, n + 1);
    swap(r[n].w, r[n].h);
}

void dfsPermute(Rect *r, int n) {
    if (n == 4) {
        dfsRotate(r, 0);
        return;
    }
    for (int i = n; i < 4; i++) {
        swap(r[n], r[i]);
        dfsPermute(r, n + 1);
        swap(r[n], r[i]);
    }
}

void input(Rect *r) {
    for (int i = 0; i < 4; i++)
        scanf("%d%d", &r[i].w, &r[i].h);
}

void process(Rect *r) { dfsPermute(r, 0); }

void output() {
    printf("%d\n", bestArea);
    for (int i = 0; i <= 100; i++)
        if (bestHt[i])
            printf("%d %d\n", i, bestArea / i);
}

int main() {
    Rect r[4];
    input(r);
    process(r);
    output();
    return 0;
}
