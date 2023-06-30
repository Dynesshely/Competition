// #include <bits/stdc++.h>
// using namespace std;
// int f[1000050],w[120],v[120];
// int main()
// {
// 	int T,n,k,i,j;
// 	scanf("%d",&T);
// 	while (T--)
// 	{
// 		memset(f,0,sizeof(f));
// 		scanf("%d%d",&n,&k);	
// 	    for (i=1;i<=n;i++)
//             scanf("%d",&w[i]);
// 		for (i=1;i<=n;i++)
//         {
//             scanf("%d",&v[i]); 
//             f[w[i]]=v[i];
//         }		  	
// 		for (i=1;i<=w[n];i++)
// 		  if (i<k)
// 			f[i]=max(f[i],f[i-1]);
// 		  else
// 			f[i]=max(f[i-k-1]+f[i],f[i-1]);
// 		printf("%d\n",f[w[n]]);		
// 	}
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int m[N], p[N], f[N];
int main(){
	int k, n, t, ma;
	cin >> t;
	while(t --){
		memset(f, 0, sizeof(f));
		ma = -1;
		cin >> n >> k;
		for(int i = 1;i <= n; i ++) cin >> m[i];
		for(int i = 1;i <= n; i ++) cin >> p[i];
		for(int i = 1;i <= n; i ++){
			f[i] = max(p[i], f[i]);
			for(int j = i + 1; j <= n; j ++){
				if(m[j] - m[i] > k)
					f[j] = max(f[j], f[i]+p[j]);
			}
			ma = max(ma, f[i]);
		}
		cout << ma << endl;
	}
	return 0;
}