#include <bits/stdc++.h>
using namespace std;
struct Node{ int x, y; };
void dfs(int x, int y, queue<Node> pos);
int maze[7][7], ans = 0x3fffffff, via[7][7];
int main(){
	memset(maze, 1, sizeof(maze)); memset(via, 0, sizeof(via));
	for(int i = 1; i <= 5; ++ i) for(int j = 1; j <= 5; ++ j) scanf("%d", &maze[i][j]);
	queue<Node> pos; dfs(1, 1, pos);
	int pss = pos.size();
	for(int i = 1; i <= pss; ++ i){
		printf("(%d, %d)\n", pos.front().x, pos.front().y);
		pos.pop();
	}
	return 0;
}
bool check(int x, int y) { return maze[y][x] == 0 && via[y][x] == 0; }
void dfs(int x, int y, queue<Node> pos){
	if(check(x, y)){
		via[y][x] = 1; pos.push({x, y});
		if(check(x - 1, y)) dfs(x - 1, y, pos);
		if(check(x, y - 1)) dfs(x, y - 1, pos);
		if(check(x + 1, y)) dfs(x + 1, y, pos);
		if(check(x, y + 1)) dfs(x, y + 1, pos);
	}else{ return; }
}