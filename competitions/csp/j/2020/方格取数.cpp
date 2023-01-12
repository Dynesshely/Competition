//#include <iostream>
//#include <cstdio>
//using namespace std;
//typedef long long LL;
//const int N = 1010;
//const LL INF = 1e17; //�����
//int n, m;
//int g[N][N];
//LL f[N][N][3];
//
//bool check(int x, int y)
//{
//    //Խ����
//    return x >= 1 && x <= n && y >= 1 && y <= m;
//}
//
////�����k���򵽴﷽��(x,y)����ߵ÷�
////k = 0����ʾ���ϱ߹���
////k = 1����ʾ���±߹���
////k = 2����ʾ����߹���
//LL dfs(int x, int y, int k)
//{
//    LL ans = f[x][y][k];    
//    //���仯��֦
//    if(f[x][y][k] != -INF) return f[x][y][k];    
//    if(k == 0)//���ϱ߹���
//    {
//        //֮ǰ�ķ���Ϊ(a,b)
//        int a = x - 1, b = y;
//        if(check(a, b))
//            //�ݹ��󵽴﷽��(a,b)�����ֵ����ʱֻ�ܴ��ϱ߻�����ߵ���(a,b)
//            ans = max(ans, max(dfs(a, b, 0), dfs(a, b, 2)));
//    }
//    else if(k == 1)//���±߹���
//    {
//        //֮ǰ�ķ���Ϊ(a,b)
//        int a = x + 1, b = y;
//        if(check(a, b))
//            //�ݹ��󵽴﷽��(a,b)�����ֵ����ʱֻ�ܴ��±߻�����ߵ���(a,b)
//            ans = max(ans, max(dfs(a, b, 1), dfs(a, b, 2)));
//    }
//    else if(k == 2) //����߹���
//    {
//        //֮ǰ�ķ���Ϊ(a,b)
//        int a = x, b = y - 1;
//        if(check(a, b)) 
//            //�ݹ��󵽴﷽��(a,b)�����ֵ����ʱ���Դ��±ߡ��ϱ߻�����ߵ���(a,b)
//            ans = max(ans, max(dfs(a, b, 0), max(dfs(a, b, 1), dfs(a, b, 2))));
//    } 
//    //���仯���� 
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
//    //��Ϊ���ڸ�������״̬��ʼ��Ϊ����С
//    for(int i = 1; i <= n; i ++)
//        for(int j = 1; j <= m; j ++)
//            f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
//          
//    //��������״̬
//    f[1][1][0] = f[1][1][1] = f[1][1][2] = g[1][1];
//    
//    //���յ�����㵹���ߣ�����ֻ�ܴ��ϱ߻�������ߵ��յ�
//    LL ans = max(dfs(n, m, 0), dfs(n, m, 2));
//    cout << ans << endl;
//    
//    return 0;
//}

// 100 �� �ⷨ�� 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1010;
int g[N][N];
LL f[N][N][3];

//���������ֵ
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
    
    //��ʼ״̬
    memset(f, -0x3f, sizeof f);
    f[1][1][0] = f[1][1][1] = f[1][1][2] = g[1][1];
    
    //ö����
    for(int i = 1; i <= m; i ++)
    {
        //�����Ŵ������ҵķ����ߵ���i�е�j��ʱ�÷ֵ����ֵ
        for(int j = 1; j <= n; j ++)
            f[i][j][0] = max(f[i][j][0], Max(f[i - 1][j][0], f[i - 1][j][1], f[i - 1][j][2]) + g[j][i]);
        
        //�ӵ�һ�е����һ��ö�٣������Ŵ������µķ����ߵ���i�е�j��ʱ�÷ֵ����ֵ
        for(int j = 1; j <= n; j ++)
            f[i][j][1] = Max(f[i][j][1], f[i][j - 1][0] + g[j][i], f[i][j - 1][1] + g[j][i]);
        
        //�����һ�п�ʼ����ö�٣������Ŵ������ϵķ����ߵ���i�е�j��ʱ�÷ֵ����ֵ
        for(int j = n; j >= 1; j --)
            f[i][j][2] = Max(f[i][j][2], f[i][j + 1][0] + g[j][i], f[i][j + 1][2] + g[j][i]);
    }
    
    //�������һ�����ӣ�ֻ�ܴ�����������浽��
    printf("%lld\n", max(f[m][n][0], f[m][n][1]));
    
    return 0;
}

//������ 
//ʧ�ܽⷨ 

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
//    for(int i = 2; i <= n; ++i)//���һ�е�״̬
//        a[i][1] = a[i-1][1] + mp[i][1];
//    for(int j = 2; j <= m; ++j)//����ʣ�¸���
//    {
//        u[n] = a[n][j-1] + mp[n][j];����u���飬���������ߣ������������һ�У�ֻ�ܴ���������
//        for(int i = n - 1; i >= 1; --i)
//            u[i] = max(u[i+1], a[i][j-1]) + mp[i][j];//����������һ�У����ܴ�����·�����
//        d[1] = a[1][j-1] + mp[1][j];//����d���飬���������ߣ������������һ�У�ֻ�ܴ�������
//        for(int i = 2; i <= n; ++i)
//            d[i] = max(d[i-1], a[i][j-1]) + mp[i][j];//����������һ�У����ܴ�����Ϸ�����
//        for(int i = 1; i <= n; ++i)//����a[i][j]
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
