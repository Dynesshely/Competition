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

//#include <bits/stdc++.h>
//using namespace std;
//struct sphere{ int x, y, z; };
//int f[1010];
//void combine(int a, int b) { f[a] = b; }
//int find(int x) { if(f[x] != x) f[x] = find(f[x]); return f[x]; }
//int dt(sphere a, sphere b) { return sqrt(pow(a.x - b.x, 2) * 1.0 + pow(a.y - b.y, 2) * 1.0 + pow(a.z - b.z, 2) * 1.0); }
//int main(){
//	int T; scanf("%d", &T);
//	while(T--){
//		int n, h, r, low[1010], up[1010], low2 = 0, up2 = 0;
//		scanf("%d %d %d", &n, &h, &r);
//		sphere ss[n + 1]; for(int i = 1; i <= n; ++ i) f[i] = i;
//		for(int i = 1; i <= n; ++ i){
//			scanf("%d %d %d", &ss[i].x, &ss[i].y, &ss[i].z);
//			for(int j = 1; j <= i; ++ j)
//				if(i != j && sqrt(dt(ss[i], ss[j])) <= 2 * r) combine(i, j);
////			if((h - ss[i].z) <= r) { up2 += 1; up[up2] = i; }
////			if(ss[i].z <= r) { low2 += 1; low[low2] = i; }
//			if((ss[i].z >= 0 && ss[i].z - r <= 0) || (0 >= ss[i].z && ss[i].z + r >= 0)) low2 += 1, low[low2] = i;
//			if((ss[i].z <= h && h <= ss[i].z + r) || (h >= ss[i].z - r && h <= ss[i].z)) up2 += 1, up[up2] = i;
//		}
//		bool has = false;
//		if(low2 != 0 && up2 != 0){
//			for(int i = 1; i <= low2; ++ i){ // low
//				for(int j = 1; j <= up2; ++ j){ // up
//					if(low[i] != up[j] && find(f[low[i]]) == find(f[up[j]])){
//						printf("Yes\n"); has = true;
//						break;
//					}
//				}
//				if(has) break;
//			}
//		}
//		if(!has) printf("No\n");
//		memset(f, 0, sizeof(f));
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int T, n, h, r, f[1010];
//struct cir{ int x, y, z; };
//bool together(int x1, int x2, int y1, int y2, int z1, int z2, int r){
//	return pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2) <= 4 * pow(r, 2);
//}
//bool check(cir a, cir b){ return together(a.x, b.x, a.y, b.y, a.z, b.z, r); }
//void combine(int a, int b) { f[a] = b; }
//int find(int x){ if(f[x] != x) f[x] = find(f[x]); return f[x]; }
//int main(){
//	scanf("%d", &T);
//	while(T--){
//		scanf("%d %d %d", &n, &h, &r);
//		cir cles[n + 1]; for(int i = 1; i <= n; ++ i) f[i] = i;
//		int low, up;
//		for(int i = 1; i <= n; ++ i){
//			scanf("%d %d %d", &cles[i].x, &cles[i].y, &cles[i].y);
//			for(int j = 1; j <= i; ++ j)
//				if(i != j && check(cles[j], cles[i])) combine(j, i);
//			if(cles[i].z - r <= 0) low = i;
//			if(h - cles[i].z <= r) up = i;
//		}
//		if(find(low) == find(up)) printf("Yes\n");
//		else printf("No\n");
//		memset(f, 0, sizeof(f));
//	}
//	return 0;
//}
