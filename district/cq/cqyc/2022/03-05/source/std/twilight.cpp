# include <cstdio>
# include <cstdlib>
# define N 1010
int n,m,tot=0,cnt[N][2],col[N];
bool g[N][N],vis[N],dp[N];
void dfs(int x,bool c) {
	int i;
	col[x]=c;
	cnt[tot][c]++;
	vis[x]=true;
	for(i=1;i<=n;i++) {
		if(x!=i && !g[x][i]) {
			if(vis[i] && col[i]==c) {
				puts("-1");
				exit(0);
			}
			else if(!vis[i]) {
				dfs(i,!c);
			}
		}
	}
	return;
}
int main() {
	freopen("twilight.in","r",stdin);
	freopen("twilight.out","w",stdout);
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		g[x][y]=g[y][x]=true;
	}
	for(i=1;i<=n;i++) {
		if(!vis[i]) {
			tot++;
			dfs(i,0);
		}
	}
	dp[0]=true;
	for(i=1;i<=tot;i++) {
		for(j=n;j>=1;j--) {
			dp[j]=j>=cnt[i][0] && dp[j-cnt[i][0]] || j>=cnt[i][1] && dp[j-cnt[i][1]];
		}
	}
	for(j=n>>1;!dp[j];j--);
	printf("%d",j);
	return 0;
}
