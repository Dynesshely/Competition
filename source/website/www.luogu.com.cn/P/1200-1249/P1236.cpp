#include <bits/stdc++.h>
using namespace std;

struct Step {
    int  x, y, res;
    char op;
};

int          a[4];
vector<Step> steps;
bool         found;

bool dfs(int arr[], int n) {
    if (n == 1)
        return arr[0] == 24;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = arr[i], y = arr[j];
            int b[4], m       = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    b[m++] = arr[k];
            {
                int r = x + y;
                b[m]  = r;
                steps.push_back({max(x, y), min(x, y), r, '+'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            }
            if (x > y) {
                int r = x - y;
                b[m]  = r;
                steps.push_back({x, y, r, '-'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            } else if (y > x) {
                int r = y - x;
                b[m]  = r;
                steps.push_back({y, x, r, '-'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            }
            {
                int r = x * y;
                b[m]  = r;
                steps.push_back({max(x, y), min(x, y), r, '*'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            }
            if (x % y == 0) {
                int r = x / y;
                b[m]  = r;
                steps.push_back({x, y, r, '/'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            }
            if (y % x == 0) {
                int r = y / x;
                b[m]  = r;
                steps.push_back({y, x, r, '/'});
                if (dfs(b, m + 1))
                    return true;
                steps.pop_back();
            }
        }
    }
    return false;
}

void input() { scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]); }

void process() { found = dfs(a, 4); }

void output() {
    if (found) {
        for (auto &s : steps)
            printf("%d%c%d=%d\n", s.x, s.op, s.y, s.res);
    } else {
        printf("No answer!\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
