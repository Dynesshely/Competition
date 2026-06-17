#include <bits/stdc++.h>
using namespace std;

char s[105];
int  cnt[26];
int  maxn, minn = 105, diff;

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void input() { scanf("%s", s); }

void process() {
    memset(cnt, 0, sizeof(cnt));
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        cnt[s[i] - 'a']++;
    maxn = 0;
    minn = 105;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] > maxn)
            maxn = cnt[i];
        if (cnt[i] < minn)
            minn = cnt[i];
    }
    diff = maxn - minn;
}

void output() {
    if (isPrime(diff))
        printf("Lucky Word\n%d\n", diff);
    else
        printf("No Answer\n0\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
