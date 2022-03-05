//http://www.cjsoj.cn/p/131
#include <bits/stdc++.h>
using namespace std;
long long n, s, e, num = 0, ls = LONG_MIN, le = LONG_MIN, lls = LONG_MIN, lle = LONG_MIN;
struct zone{ long long x, y; };
queue<zone> que;
bool lastCover = false;
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; ++ i){
    	scanf("%lld %lld", &s, &e);
    	que.push({s, e});
	}
	for(int i = 0; i < n; ++ i){
		zone tz = que.front();
		if(lastCover){ // cover && lastCover = true
			if(!(tz.x > lls && tz.x < lle)) num ++;
		}
		if(!(tz.x > ls && tz.x < le)){ num ++; lastCover = false; } // no cover
		else lastCover = true;
		lls = ls, lle = le, ls = tz.x, le = tz.y;
		que.push(que.front()); que.pop();
	}
	printf("%lld\n", num);
    return 0;
}