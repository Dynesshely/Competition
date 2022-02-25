#include <bits/stdc++.h>
using namespace std;
int t, n, h, r, x[1005], y[1005], z[1005], f[1005];
bool is[1005];
int get(int x){
	if(f[x] != x) f[x] = get(f[x]);
	return f[x];
}
double dis(int i,int j){
	return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j])+1.0*(z[i]-z[j])*(z[i]-z[j]));
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &h, &r);
		for(int i = 1; i <= n; ++ i){
			f[i] = i, is[i] = 0;
			scanf("%d %d %d", &x[i], &y[i], &z[i]);
			is[i] = ((h - z[i]) <= r);
			for(int j = i - 1, fj, fi; j >= 1; -- j){
				fi = get(i); fj = get(j);
				if(fi != fj && dis(j,i) <= 2.0 * r){
					f[fi] = fj, is[fj] = (is[fi] || is[fj]);
				}
			}
		}
		bool has = 0;
		for(int i = 1; i <= n; ++ i)
			if(z[i] <= r && is[get(i)]){
				has = 1; printf("Yes\n"); break;
			}
		if(!has) printf("No\n");
	}
	return 0;
}