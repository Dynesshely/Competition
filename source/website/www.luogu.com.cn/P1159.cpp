#include <bits/stdc++.h>
using namespace std;

int  n;
char name[105][105];
char stat[105][10];
int  ans[105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s%s", name[i], stat[i]);
}

void process() {
    for (int i = 0; i < n; i++)
        ans[i] = -1;
    for (int i = 0; i < n; i++)
        if (stat[i][0] == 'S')
            ans[i] = i;
    vector<pair<int, int>> up, down;
    for (int i = 0; i < n; i++) {
        if (stat[i][0] == 'U')
            up.push_back({i, i});
        if (stat[i][0] == 'D')
            down.push_back({i, i});
    }
    sort(up.rbegin(), up.rend());
    for (auto &p : up) {
        int cur = p.first;
        for (int j = n - 1; j > cur; j--)
            if (ans[j] == -1) {
                ans[j] = cur;
                break;
            }
    }
    sort(down.begin(), down.end());
    for (auto &p : down) {
        int cur = p.first;
        for (int j = 0; j < cur; j++)
            if (ans[j] == -1) {
                ans[j] = cur;
                break;
            }
    }
}

void output() {
    for (int i = 0; i < n; i++)
        printf("%s\n", name[ans[i]]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
