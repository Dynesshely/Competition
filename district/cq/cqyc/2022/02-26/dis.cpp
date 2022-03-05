#include <bits/stdc++.h>
using namespace std;

/*
    好难 😑
    只能暴力了。。。

    复杂度分析：
    1. 输入 O(n)
    2. 主体
        1.  每取出一个 j ，向后遍历所有剩余的 a[k]，
            复杂度为：O(n + n - 1 + n - 2 + ... + n - n + 1)
            即：O(n^2 - n) = O(n(n - 1))
            依旧是 n^2 级别算法，因该能拿50分
    3. 输出 O(1)
*/

const int maxn = 1000100;
const int maxa = 1000000010;

int n, m, l, r, a[maxn];
int main(){
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; ++ i){
        scanf("%d %d", &l, &r);
        int ans = maxa;
        for(int j = l; j <= r; ++ j){
            for(int k = j + 1; k <= r; ++ k){
                if(a[j] == a[k]){
                    ans = min(ans, abs(j - k));
                    // debug[1]
                }
            }
            // debug[2]
        }
        if(ans == maxa) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}

/*
    debug:
        [1]: printf("\ndebug >> %d == %d , del = %d\n", a[j], a[k], abs(j - k));
        [2]: printf("\ndebug >> %d\n", j);
*/
