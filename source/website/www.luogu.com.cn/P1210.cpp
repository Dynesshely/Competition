#include <bits/stdc++.h>
using namespace std;

string      s, t;
vector<int> pos;
int         bestLen, bestStart, bestEnd;

void input() {
    int c;
    while ((c = getchar()) != EOF)
        s.push_back(c);
    for (int i = 0; i < (int)s.size(); ++i)
        if (isalpha(s[i])) {
            t.push_back(tolower(s[i]));
            pos.push_back(i);
        }
}

void process() {
    int n = t.size();
    if (!n)
        return;
    vector<int> d1(n);
    int         l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k])
            ++k;
        d1[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
        int len = 2 * d1[i] - 1;
        if (len > bestLen) {
            bestLen   = len;
            bestStart = pos[i - d1[i] + 1];
            bestEnd   = pos[i + d1[i] - 1];
        }
    }
    vector<int> d2(n);
    l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && t[i - k - 1] == t[i + k])
            ++k;
        d2[i] = k--;
        if (i + k > r)
            l = i - k - 1, r = i + k;
        int len = 2 * d2[i];
        if (len > bestLen) {
            bestLen   = len;
            bestStart = pos[i - d2[i]];
            bestEnd   = pos[i + d2[i] - 1];
        }
    }
}

void output() {
    printf("%d\n", bestLen);
    if (bestLen)
        for (int i = bestStart; i <= bestEnd; ++i)
            printf("%c", s[i]);
    if (bestLen)
        printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
