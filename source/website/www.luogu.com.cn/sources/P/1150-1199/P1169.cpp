#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2005][2005];
int dp[2005][2005];
int height[2005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

int maxSquare(int mat[][2005], int n, int m) {
    int maxSide = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                if (dp[i][j] > maxSide)
                    maxSide = dp[i][j];
            } else
                dp[i][j] = 0;
        }
    return maxSide * maxSide;
}

int maxRect(int mat[][2005], int n, int m) {
    memset(height, 0, sizeof(height));
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        stack<int> st;
        for (int j = 0; j <= m; j++) {
            int h = (j == m) ? 0 : height[j];
            while (!st.empty() && h <= height[st.top()]) {
                int ht = height[st.top()];
                st.pop();
                int w = st.empty() ? j : j - st.top() - 1;
                if (ht * w > maxArea)
                    maxArea = ht * w;
            }
            if (j < m)
                st.push(j);
        }
    }
    return maxArea;
}

void process() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i + j) & 1)
                a[i][j] = 1 - a[i][j];
    int sq1   = maxSquare(a, n, m);
    int rect1 = maxRect(a, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 1 - a[i][j];
    int sq2   = maxSquare(a, n, m);
    int rect2 = maxRect(a, n, m);
    printf("%d\n%d\n", max(sq1, sq2), max(rect1, rect2));
}

int main() {
    input();
    process();
    return 0;
}
