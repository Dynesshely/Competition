#include <bits/stdc++.h>
using namespace std;
struct point{
	int x;
	int y;
};
int _map[100][100], n, m;
void via(int x, int y){
	_map[y][x] = 0;
	if(y + 1 < n && _map[y + 1][x] == 1){
		via(x, y + 1);
	}
	if(y - 1 >= 0 && _map[y - 1][x] == 1){
		via(x, y - 1);
	}
	if(x - 1 >= 0 && _map[y][x - 1] == 1){
		via(x - 1, y);
	}
	if(x + 1 < m && _map[y][x + 1] == 1){
		via(x + 1, y);
	}
}
int main(){
	queue<point> que;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &_map[i][j]);
			if(_map[i][j] == 1){
				point p;
				p.x = j; p.y = i;
				que.push(p);
			}
		}
	}
	int count = 0;
	while(!que.empty()){
		point *p = &que.front();
		if(_map[p->y][p->x] != 0){
			count ++;
			via(p->x, p->y);
		}
		que.pop();
	}
	printf("%d\n", count);
	return 0;
}
