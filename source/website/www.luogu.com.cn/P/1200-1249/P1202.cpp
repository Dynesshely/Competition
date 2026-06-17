#include <bits/stdc++.h>
using namespace std;

int n, cnt[7];

bool isLeap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }

void input() { scanf("%d", &n); }

void process() {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dow           = 0;
    for (int y = 1900; y < 1900 + n; y++) {
        bool leap = isLeap(y);
        for (int m = 0; m < 12; m++) {
            int days = daysInMonth[m];
            if (m == 1 && leap)
                days = 29;
            cnt[(dow + 12) % 7]++;
            dow = (dow + days) % 7;
        }
    }
}

void output() { printf("%d %d %d %d %d %d %d\n", cnt[5], cnt[6], cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]); }

int main() {
    input();
    process();
    output();
    return 0;
}
