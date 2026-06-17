#include <bits/stdc++.h>
using namespace std;

int         n, m;
vector<int> rowCost, colCost;

void input() {
    scanf("%d%d", &n, &m);
    rowCost.resize(n - 1);
    colCost.resize(m - 1);
    for (int i = 0; i < n - 1; ++i)
        scanf("%d", &rowCost[i]);
    for (int i = 0; i < m - 1; ++i)
        scanf("%d", &colCost[i]);
}

long long process() {
    sort(rowCost.begin(), rowCost.end(), greater<int>());
    sort(colCost.begin(), colCost.end(), greater<int>());
    long long ans = 0;
    int       i = 0, j = 0, rCnt = 1, cCnt = 1;
    while (i < n - 1 || j < m - 1) {
        if (j == m - 1 || (i < n - 1 && rowCost[i] > colCost[j])) {
            ans += (long long)rowCost[i] * cCnt;
            ++i;
            ++rCnt;
        } else {
            ans += (long long)colCost[j] * rCnt;
            ++j;
            ++cCnt;
        }
    }
    return ans;
}

void output(long long res) { printf("%lld\n", res); }

int main() {
    input();
    output(process());
    return 0;
}
