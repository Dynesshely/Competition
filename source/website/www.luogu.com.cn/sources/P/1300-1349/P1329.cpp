#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long          ll;

int  n;
ll   s;
ull  total, target;
ull  cnt[101][5001];
bool ex[101][5001];
int  outCnt;

void input() {
    if (scanf("%d%lld", &n, &s) != 2)
        n = 0, s = 0;
}

void process() {
    ll totalSigned = (ll)n * (n - 1) / 2;
    if (s < -totalSigned || s > totalSigned) {
        target = 0;
        return;
    }
    ll tmp = s + totalSigned;
    if (tmp % 2 != 0) {
        target = 0;
        return;
    }
    total  = (ull)totalSigned;
    target = (ull)(tmp / 2);

    cnt[n][0] = 1;
    ex[n][0]  = true;

    for (int j = n - 1; j >= 1; j--) {
        int w = n - j;
        for (ull sm = 0; sm <= total; sm++) {
            cnt[j][sm] = cnt[j + 1][sm];
            ex[j][sm]  = ex[j + 1][sm];
            if (sm >= (ull)w) {
                cnt[j][sm] += cnt[j + 1][sm - w];
                if (ex[j + 1][sm - w])
                    ex[j][sm] = true;
            }
        }
    }
}

void gen(int j, ull rem, vector<int> &seq) {
    if (outCnt >= 100)
        return;
    if (j == n) {
        if (rem == 0) {
            for (int i = 0; i < n; i++)
                printf("%d%c", seq[i], i == n - 1 ? '\n' : ' ');
            outCnt++;
        }
        return;
    }
    int w = n - j;
    if (ex[j + 1][rem]) {
        seq.push_back(seq.back() - 1);
        gen(j + 1, rem, seq);
        seq.pop_back();
    }
    if (rem >= (ull)w && ex[j + 1][rem - w]) {
        seq.push_back(seq.back() + 1);
        gen(j + 1, rem - w, seq);
        seq.pop_back();
    }
}

void output() {
    if (target <= total && ex[1][target]) {
        printf("%llu\n", cnt[1][target]);
        vector<int> seq;
        seq.push_back(0);
        outCnt = 0;
        gen(1, target, seq);
    } else {
        printf("0\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
