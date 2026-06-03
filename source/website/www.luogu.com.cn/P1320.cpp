#include <bits/stdc++.h>
using namespace std;

int n;
string grid;
vector<int> ans;

void input() {
    char buf[205];
    scanf("%s", buf);
    n = strlen(buf);
    grid = buf;
    for (int i = 1; i < n; i++) {
        scanf("%s", buf);
        grid += buf;
    }
}

void process() {
    ans.push_back(n);
    char cur = '0';
    int cnt = 0;
    for (int i = 0; i < n * n; i++) {
        if (grid[i] == cur)
            cnt++;
        else {
            ans.push_back(cnt);
            cur = grid[i];
            cnt = 1;
        }
    }
    ans.push_back(cnt);
}

void output() {
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
