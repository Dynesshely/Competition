//#include <iostream>
//#include <cstdio>
//using namespace std;
//typedef long long LL;
//const int N = 1010;
//const LL INF = 1e17; //无穷大
//int n, m;
//int g[N][N];
//LL f[N][N][3];
//
//bool check(int x, int y)
//{
//    //越界检查
//    return x >= 1 && x <= n && y >= 1 && y <= m;
//}
//
////计算从k方向到达方格(x,y)的最高得分
////k = 0，表示从上边过来
////k = 1，表示从下边过来
////k = 2，表示从左边过来
//LL dfs(int x, int y, int k)
//{
//    LL ans = f[x][y][k];    
//    //记忆化剪枝
//    if(f[x][y][k] != -INF) return f[x][y][k];    
//    if(k == 0)//从上边过来
//    {
//        //之前的方格为(a,b)
//        int a = x - 1, b = y;
//        if(check(a, b))
//            //递归求到达方格(a,b)的最大值，此时只能从上边或者左边到达(a,b)
//            ans = max(ans, max(dfs(a, b, 0), dfs(a, b, 2)));
//    }
//    else if(k == 1)//从下边过来
//    {
//        //之前的方格为(a,b)
//        int a = x + 1, b = y;
//        if(check(a, b))
//            //递归求到达方格(a,b)的最大值，此时只能从下边或者左边到达(a,b)
//            ans = max(ans, max(dfs(a, b, 1), dfs(a, b, 2)));
//    }
//    else if(k == 2) //从左边过来
//    {
//        //之前的方格为(a,b)
//        int a = x, b = y - 1;
//        if(check(a, b)) 
//            //递归求到达方格(a,b)的最大值，此时可以从下边、上边或者左边到达(a,b)
//            ans = max(ans, max(dfs(a, b, 0), max(dfs(a, b, 1), dfs(a, b, 2))));
//    } 
//    //记忆化搜索 
//    return f[x][y][k] = ans + g[x][y];
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);
//    
//    for(int i = 1; i <= n; i ++)
//        for(int j = 1; j <= m; j ++)
//            scanf("%d", &g[i][j]);
//    
//    //因为存在负数，将状态初始化为无穷小
//    for(int i = 1; i <= n; i ++)
//        for(int j = 1; j <= m; j ++)
//            f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
//          
//    //设置起点的状态
//    f[1][1][0] = f[1][1][1] = f[1][1][2] = g[1][1];
//    
//    //从终点向起点倒着走，而且只能从上边或者左边走到终点
//    LL ans = max(dfs(n, m, 0), dfs(n, m, 2));
//    cout << ans << endl;
//    
//    return 0;
//}

// 100 分 解法二 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1010;
int g[N][N];
LL f[N][N][3];

//求三数最大值
LL Max(LL a, LL b, LL c)
{
    return max(a, max(b, c));
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d", &g[i][j]);
    
    //初始状态
    memset(f, -0x3f, sizeof f);
    f[1][1][0] = f[1][1][1] = f[1][1][2] = g[1][1];
    
    //枚举列
    for(int i = 1; i <= m; i ++)
    {
        //求沿着从左向右的方向走到第i列第j行时得分的最大值
        for(int j = 1; j <= n; j ++)
            f[i][j][0] = max(f[i][j][0], Max(f[i - 1][j][0], f[i - 1][j][1], f[i - 1][j][2]) + g[j][i]);
        
        //从第一行到最后一行枚举，求沿着从上向下的方向走到第i列第j行时得分的最大值
        for(int j = 1; j <= n; j ++)
            f[i][j][1] = Max(f[i][j][1], f[i][j - 1][0] + g[j][i], f[i][j - 1][1] + g[j][i]);
        
        //从最后一行开始向上枚举，求沿着从下向上的方向走到第i列第j行时得分的最大值
        for(int j = n; j >= 1; j --)
            f[i][j][2] = Max(f[i][j][2], f[i][j + 1][0] + g[j][i], f[i][j + 1][2] + g[j][i]);
    }
    
    //对于最后一个格子，只能从左面或者上面到达
    printf("%lld\n", max(f[m][n][0], f[m][n][1]));
    
    return 0;
}

//以下是 
//失败解法 

//#include<bits/stdc++.h>
//using namespace std;
//#define N 1005
//long long mp[N][N], a[N][N], u[N], d[N];
//int main()
//{
//    int n, m;
//    cin>>n>>m;
//    for(int i = 1; i <= n; ++i)
//        for(int j = 1; j <= m; ++j)
//            cin>>mp[i][j];
//    a[1][1] = mp[1][1];
//    for(int i = 2; i <= n; ++i)//求第一列的状态
//        a[i][1] = a[i-1][1] + mp[i][1];
//    for(int j = 2; j <= m; ++j)//遍历剩下各列
//    {
//        u[n] = a[n][j-1] + mp[n][j];生成u数组，从下向上走，如果是最下面一行，只能从左走来。
//        for(int i = n - 1; i >= 1; --i)
//            u[i] = max(u[i+1], a[i][j-1]) + mp[i][j];//不是最下面一行，可能从左或下方来。
//        d[1] = a[1][j-1] + mp[1][j];//生成d数组，从上向下走，如果是最上面一行，只能从左走来
//        for(int i = 2; i <= n; ++i)
//            d[i] = max(d[i-1], a[i][j-1]) + mp[i][j];//不是最上面一行，可能从左或上方来。
//        for(int i = 1; i <= n; ++i)//生成a[i][j]
//            a[i][j] = max(u[i], d[i]);
//    }
//    cout<<a[n][m];
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int n;
//int a[10][10];
//int dp[20][20][20];
//
//int main(){
//	cin>>n;
//	int x,y,k;
//	while(cin>>x>>y>>k){
//		if(x==0 &&y==0 &&k==0){
//			break;
//		}
//		a[x][y]=k;
//	}
//	
//	for(int i=1;i<=n*2-1;i++){
//		for(int j=1;j<=n && j<=i;j++){
//			for(int k=1;k<=n && k<=i;k++){
//					dp[i][j][k] = max(max(dp[i-1][j-1][k-1],dp[i-1][j][k-1]),
//										max(dp[i-1][j-1][k],dp[i-1][j][k]))
//									+a[j][i-j+1] +a[k][i-k+1];
//					if(j==k){
//						dp[i][j][k] -= a[j][i-j+1];
//					}
//				
//			}
//		}
//	}
//	cout<<dp[n+n-1][n][n];
//	return 0;
//}

//#include <iostream>

//using namespace std;
//int n,i,j,tmp,k,l;
//int puz[20][20], dp[20][20][20][20];
//int main()
//{
//       scanf("%d",&n);
//       while(scanf("%d%d%d", &i, &j, &tmp) && i)
//        puz[i][j] = tmp;    
//          for(i = 1;i <= n; i++)
//              for(j = 1; j <= n; j++)
//                  for(k = 1; k <= n; k++)
//                      for(l = 1; l <= n; l++) {
//                              dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1]),
//                                                                               max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l]))+puz[i][j];
//                             if(i != k||j != l) dp[i][j][k][l] += puz[k][l];
//                             }
//        printf("%d\n", dp[n][n][n][n]);
//        return 0;
//}
