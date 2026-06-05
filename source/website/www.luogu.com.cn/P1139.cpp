#include <bits/stdc++.h>
using namespace std;

int  n;
char str[20];
int  md[20];
int  s[4][20];
int  cnt[4];
int  from[100], to[100], ans[100];
int  Rank[20];
int  lim;

void input() {
    scanf("%d%s", &n, str + 1);
    for (int i = 1; i <= n; i++) {
        md[n - i + 1]       = str[i] - 'a' + 1;
        s[0][++cnt[0]]      = i;
        Rank[md[n - i + 1]] = n - i + 1;
    }
}

void dfs(int step, int last) {
    if (s[3][cnt[3]] != md[cnt[3]])
        return;
    if (lim - step + 1 < n - cnt[3])
        return;
    if (step == lim + 1 && !(cnt[0] + cnt[1] + cnt[2])) {
        for (int i = 1; i < step; i++)
            printf("%c %c %c\n", ans[i] + 'a' - 1, from[i] + 'A', to[i] + 'A');
        exit(0);
    }
    if (step > lim)
        return;
    for (int i = 0; i <= 2; i++) {
        if (i == last)
            continue;
        if (s[i][cnt[i]] == md[cnt[3] + 1]) {
            int tmp   = s[i][cnt[i]--];
            ans[step] = s[3][++cnt[3]] = tmp;
            from[step]                 = i;
            to[step]                   = 3;
            dfs(step + 1, 3);
            s[i][++cnt[i]] = tmp;
            cnt[3]--;
            return;
        }
        for (int j = i + 1; j <= 3 && cnt[i]; j++) {
            if (j == 2 && cnt[2] && Rank[s[i][cnt[i]]] >= Rank[s[2][cnt[2]]])
                continue;
            int tmp        = s[i][cnt[i]--];
            s[j][++cnt[j]] = ans[step] = tmp;
            from[step]                 = i;
            to[step]                   = j;
            dfs(step + 1, j);
            s[i][++cnt[i]] = tmp;
            cnt[j]--;
        }
    }
}

void process() {
    for (lim = n; lim <= 3 * n; lim++) {
        dfs(1, -1);
    }
    printf("NO\n");
}

int main() {
    input();
    process();
    return 0;
}
