#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int a[maxn], alpha[maxn], length;
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

int process(char* input, int length){
	int status = 0;
	ostringstream os;
	for(int i = 0; i < length; ++ i){
		os << input[i] << " " << i << " ";
		os << os.str();
	}
	stirng s = os.str();
	for(int j = length - 1; j >= 0; -- j){
		status += s[j] + s[length - j];
	}
	return status;
}

int main(){
	memset(vis, true, sizeof(vis));
	freopen("war.in", "r", stdin);
	scanf("%d", &length);
	freopen("war.out", "w", stdout);
	printf("-1\n");
	freopen("war.ans", "w", stdout);
	printf("-1\n");
	for(int i = 0; i <= 10; ++ i){
		ostringstream fn;
		fn << "war" << i << ".ans";
		freopen(fn.str().c_str(), "w", stdout);
		printf("-1\n");
	}
	return 0;
}
