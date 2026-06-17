#include <bits/stdc++.h>
using namespace std;

int                        n, m, total, l, distinct, ans;
char                       word[15];
unordered_map<string, int> id;
int                        art[100005];
int                        cnt[1005];
bool                       seen[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        id[word] = i;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", word);
        auto it = id.find(word);
        art[i]  = it == id.end() ? -1 : it->second;
    }
}

void process() {
    for (int i = 0; i < m; i++)
        if (art[i] != -1 && !seen[art[i]]) {
            seen[art[i]] = true;
            total++;
        }
    if (!total) {
        ans = 0;
        return;
    }
    ans = m + 1;
    for (int r = 0; r < m; r++) {
        if (art[r] != -1) {
            cnt[art[r]]++;
            if (cnt[art[r]] == 1)
                distinct++;
        }
        while (distinct == total) {
            if (r - l + 1 < ans)
                ans = r - l + 1;
            if (art[l] != -1) {
                cnt[art[l]]--;
                if (cnt[art[l]] == 0)
                    distinct--;
            }
            l++;
        }
    }
}

void output() { printf("%d\n%d\n", total, ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
