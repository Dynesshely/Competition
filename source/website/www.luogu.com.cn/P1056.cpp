#include <cstdio>
#include <algorithm>
using namespace std;

struct Aisle {
    int pos, cnt;
} hor[1005], ver[1005];

bool cmp_cnt(const Aisle &a, const Aisle &b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.pos < b.pos;
}

bool cmp_pos(const Aisle &a, const Aisle &b) {
    return a.pos < b.pos;
}

int main() {
    int M, N, K, L, D;
    scanf("%d%d%d%d%d", &M, &N, &K, &L, &D);
    for (int i = 1; i < M; ++i) hor[i].pos = i;
    for (int i = 1; i < N; ++i) ver[i].pos = i;
    for (int i = 0; i < D; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            int c = y1 < y2 ? y1 : y2;
            ++ver[c].cnt;
        } else {
            int r = x1 < x2 ? x1 : x2;
            ++hor[r].cnt;
        }
    }
    sort(hor + 1, hor + M, cmp_cnt);
    sort(ver + 1, ver + N, cmp_cnt);
    sort(hor + 1, hor + 1 + K, cmp_pos);
    sort(ver + 1, ver + 1 + L, cmp_pos);
    for (int i = 1; i <= K; ++i)
        printf("%d%c", hor[i].pos, i == K ? '\n' : ' ');
    if (K == 0) putchar('\n');
    for (int i = 1; i <= L; ++i)
        printf("%d%c", ver[i].pos, i == L ? '\n' : ' ');
    if (L == 0) putchar('\n');
    return 0;
}
