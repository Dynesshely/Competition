#include <bits/stdc++.h>
using namespace std;
int reach[10][10], cnt[10];
char s[40];
void mul(vector<int> &v, int c) {
    int carry = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = v[i] * c + carry;
        carry = v[i] / 10;
        v[i] %= 10;
    }
    while (carry) { v.push_back(carry % 10); carry /= 10; }
}
int main() {
    int k;
    scanf("%s%d", s, &k);
    for (int i = 0; i < k; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        reach[a][b] = 1;
    }
    for (int i = 0; i < 10; ++i) reach[i][i] = 1;
    for (int m = 0; m < 10; ++m)
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                if (reach[i][m] && reach[m][j]) reach[i][j] = 1;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) cnt[i] += reach[i][j];
    vector<int> ans(1, 1);
    for (int i = 0; s[i]; ++i) mul(ans, cnt[s[i] - '0']);
    for (int i = (int)ans.size() - 1; i >= 0; --i) putchar(ans[i] + '0');
    putchar('\n');
    return 0;
}
