#include <bits/stdc++.h>
using namespace std;
template <class T> inline void read(T &x) {
	x= 0;
	char c= getchar();
	while(!isdigit(c)) c= getchar();
	while(isdigit(c)) x= x * 10 + (c & 15), c= getchar();
}
#define N 100005
#define M 1000005
int n, a[N], cnt[M], sum[M], m, b[M];
long long ans;
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i= 1; i <= n; i++) read(a[i]), ++cnt[a[i]], m= max(m, a[i]);
	for(int i= 1; i <= m; i++) sum[i]= sum[i - 1] + cnt[i];
	for(int i= 1; i <= m; i++) {
		int tot= m / i;
		for(int j= 1; j <= tot; j++) b[j]= sum[min((j + 1) * i - 1, m)] - sum[j * i - 1];
		int bb= 0;
		for(int j= 1; j <= tot; j++) bb+= b[j] & 1;
		if(bb > 2 || bb == 0) continue;
		if(bb == 1) {
			if(b[1] & 1) ans+= b[1];
		} else if(bb == 2) {
			for(int j= 2; j <= tot; j++)
				if((b[j] & 1) && (b[j - 1] & 1)) ans+= b[j];
		}
	}
	printf("%lld", ans);
	return 0;
}
