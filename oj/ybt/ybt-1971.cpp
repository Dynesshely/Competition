#include <bits/stdc++.h>
using namespace std;
struct block{
	int color;
	int num;
}blocks[100001];
int main(){
	int n, m;
	long long score = 0;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;++i){
		scanf("%d", &blocks[i].num);
	}
	for(int i=1;i<=n;++i){
		scanf("%d", &blocks[i].color);
	}
	for(int z=1;z<=n;++z){
		for(int y=1;y<z;++y){
			for(int x=1;x<y;++x){
				if(y - x == z - y && blocks[x].color == blocks[z].color){
					score += (x + z) * (blocks[x].num + blocks[z].num);
				}
			}
		}
	}
	printf("%lld\n", score % 10007);
	return 0;
}
