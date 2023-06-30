#include <bits/stdc++.h>
using namespace std;
struct toy{
	int dir, last, next;
	string job;
};
int main(){
	int n, m, last = 0, a, b, pos = 0;
	scanf("%d %d", &n, &m);
	toy toys[n];
	for(int i = 0; i < n; ++ i){
		cin >> toys[i].dir >> toys[i].job;
		toys[last].next = i, toys[i].last = last;
		last = i;
		if(i == n - 1) toys[i].next = 0, toys[0].last = i;
	}
	for(int i = 0; i < m; ++ i){
		scanf("%d %d", &a, &b);
		if(toys[pos].dir == 0){
			if(a == 0) pos = b + pos >= n ? n - ((b + pos) % n) : n - (b + pos);
			else pos = b + pos >= n ? (b + pos) % n : b + pos;
		}else{
			if(a == 0) pos = b + pos >= n ? (b + pos) % n : b + pos;
			else pos = b + pos >= n ? n - ((b + pos) % n) : n - (b + pos);
		}
//		if(toys[pos].dir == 0){
//			if(a == 0) pos = toys[pos].last;
//			else pos = toys[pos].next;
//		}else{
//			while(b --){
//				if(a == 0) pos = toys[pos].next;
//				else pos = toys[pos].last;
//			}
//		}
	}
	printf("%s\n", toys[pos].job.c_str());
	return 0;
}