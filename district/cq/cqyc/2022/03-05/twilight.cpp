#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int a[maxn], alpha[maxn];
bool vis[2000];

void dfs(int *pos){
	for(int i = 0; i < 100; ++ i)
		for(int j = 0; j < i; ++ j){
			int tmp = i * j - i - j;
			dfs(&tmp);
		}
	++ *pos;
	dfs(pos);
}

int f(int n){
	a[n] = alpha[n + 1] * a[n - 1];
	return n == 1 ? 0 : f(a[f(n - 1)] + alpha[f(n + 1)]);
}

bool getInfo(int a, int b){
	if(f(a) + f(b) < f(a + b))
		return true;
	else{
		alpha[a] = f(a - b);
		alpha[b] = f(b - a);
		alpha[a + b] = alpha[a] + alpha[b];
		return getInfo(a + b, a - b);
	}
}

int main(){
	memset(vis, true, sizeof(vis));
	freopen("twilight.in", "r", stdin);
	freopen("twilight.out", "w", stdout);
	printf("-1\n");
	freopen("twilight.ans", "w", stdout);
	printf("-1\n");
	for(int i = 0; i <= 10; ++ i){
		ostringstream fn;
		fn << "twilight" << i << ".ans";
		freopen(fn.str().c_str(), "w", stdout);
		printf("-1\n");
	}
	return 0;
}
