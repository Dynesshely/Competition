// #include <bits/stdc++.h>
// using namespace std;
// int turns = 0, length = 0;
// int main(){
//     scanf("%d", &turns);
//     while(turns --){
//         scanf("%d", &length);
//         int nums[length], dp[length] = {}, big = 0, ans = 0; // nums - 3 19 10 6
//         for(int i = 0; i < length; i ++){
//             scanf("%d", &nums[i]);
//             big = max(nums[i], big);
//         }
//         dp[0] = 1;
//         int call[big + 1]; // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
//         for(int i = 0; i <= big; i ++){
//             call[i] = i;
//         }
//         for(int i = 0; i < length; i ++){
//             for(int j = 0; j < length; j ++){

//             }
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[110];
bool flag[50010];
int main() {
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        memset(flag, false, sizeof(flag));
        int ans = 0, maxn = INT_MIN;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), maxn = max(maxn, a[i]);
        sort(a + 1, a + n + 1);
        flag[0] = true;
        for (int i = 1; i <= n; i++) {
            if (!flag[a[i]])
                ans++;
            for (int j = 0; j <= maxn; j++)
                if (flag[j])
                    flag[j + a[i]] = true;
        }
        printf("%d\n", ans);
    }
    return 0;
}