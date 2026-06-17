#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull readUll() {
    ull  x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int readInt() {
    int  x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main() {
    int T = readInt();
    while (T--) {
        int         n = readInt(), m = readInt();
        vector<ull> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = readUll();

        int xorSum = 0, j = 0;

        if (m) {
            ull cur = readUll();
            int cnt = 1;
            for (int i = 1; i < m; ++i) {
                ull x = readUll();
                if (x == cur)
                    ++cnt;
                else {
                    while (j < n && a[j] < cur)
                        ++j;
                    if (j < n && a[j] == cur) {
                        xorSum ^= cnt;
                        ++j;
                    }
                    cur = x;
                    cnt = 1;
                }
            }
            while (j < n && a[j] < cur)
                ++j;
            if (j < n && a[j] == cur) {
                xorSum ^= cnt;
                ++j;
            }
        }

        printf("%d\n", xorSum);
    }
    return 0;
}
