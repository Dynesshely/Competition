/*
	贵青杯赛事题或者训练题
*/

#include<bits/stdc++.h>
using namespace std;
char maze[1005][1005];
int n, m, sx, sy, cnt, vis[1005][1005], dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int in(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i ++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(in(tx, ty) && !vis[tx][ty] && maze[tx][ty] == '#'){
            cnt++; dfs(tx,ty);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    int i, j;
    for(i = 0; i < n; i ++){
        scanf("%s", maze[i]);
    }
    int max = 0;
    for(i = 0; i < n; i ++){
        for(j = 0; j < m; j ++){
            if(maze[i][j] == '#' && !vis[i][j]){
                cnt=1; sx=i; sy=j; dfs(sx, sy); 
                if(cnt > max) max = cnt;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}