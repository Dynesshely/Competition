#include <bits/stdc++.h>
using namespace std;
int n, m, val[21][21], t = 0;
struct point{ int x, y ; } ps[402];
bool cmp(point a, point b){ return val[a.x][a.y] < val[b.x][b.y]; }
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1, j = 1; i <= n && j <= m; i = j == m ? i + 1 : i, j = j == m ? 1 : j + 1){
		scanf("%d", &val[i][j]);
		ps[t].x = i, ps[t].y = j, t += 1;
	}
	sort(ps, ps + t, cmp);
	for(int i = 0; i < t; ++ i) printf("(%d,%d) ", ps[i].x, ps[i].y);
	printf("\n");
	return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//const int MAXINT = 2100000000;
//int n, m, arr[22][22], via[22][22], nx, ny, MIN = MAXINT;
//int main(){
//	scanf("%d %d", &n, &m);
//	for(int i = 0; i < 22; ++ i) for(int j = 0; j < 22; ++ j) arr[i][j] = MAXINT, via[i][j] = 1;
//	for(int i = 1, j = 1; i <= n && j <= m; i = j == m ? i + 1 : i, j = j == m ? 1 : j + 1){
//		scanf("%d", &arr[i][j]); via[i][j] = 0;
//		if(arr[i][j] < MIN) MIN = arr[i][j], nx = j, ny = i;
//	}
//	while(via[ny - 1][nx] == 0 || via[ny + 1][nx] == 0 || via[ny][nx - 1] == 0 || via[ny][nx + 1] == 0){
//		printf("(%d,%d) ", ny, nx);
//		via[ny][nx] = 1;
//		int u = arr[ny - 1][nx], d = arr[ny + 1][nx], l = arr[ny][nx - 1], r = arr[ny][nx + 1];
//		if(via[ny - 1][nx] == 0 && u < l && u < r && u < d) ny --;
//		else if(via[ny + 1][nx] == 0 && d < l && d < u && d < r) ny ++;
//		else if(via[ny][nx - 1] == 0 && l < d && l < r && l < u) nx --;
//		else if(via[ny][nx + 1] == 0 && r < l && r < d && r < u) nx ++;
//		else break;
//	}
//	printf("\n");
//	return 0;
//}
