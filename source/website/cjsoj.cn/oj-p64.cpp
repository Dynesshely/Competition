#include <bits/stdc++.h>
using namespace std;
int T;
void solve();
int main(){
	scanf("%d", &T);
	for(int i = 1; i <= T; ++ i) solve();
	return 0;
}

int maxcantpay(int a, int b) { return a * b - a - b ;}
int e_gcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1, y = 0; return a;
	}
	int ans = e_gcd(b, a%b, x, y), temp = x;
	x = y, y = temp - a / b * y;
	return ans;
}

void solve(){
	int n;
	scanf("%d", &n);
	int m[n + 1], sum = 0;
	memset(m, -1, sizeof(m));
	for(int i = 1; i <= n; ++ i) scanf("%d", &m[i]);
	for(int i = 1; i <= n; ++ i)
		for(int j = i + 1; j <= n; ++ j){
			if(m[i] != -1 && m[j] != -1){
				if(m[i] % m[j] == 0){
					m[i] = -1;
					break;
				}
				if(m[j] % m[i] == 0){
					m[j] = -1;
					break;	
				}	
			}
		}
	for(int i = 1; i <= n; ++ i)
		for(int j = i + 1; j <= n; ++ j)
			if(m[i] != -1 && m[j] != -1){
				int mcp = maxcantpay(m[i], m[j]);
				for(int s = 1; s <= n; ++ s) if(m[s] > mcp) m[s] = -1;
				for(int s = 1; s <= n; ++ s){
					
				}
			}
	for(int i = 1; i <= n; ++ i) if(m[i] != -1) ++ sum;
	printf("%d\n", sum);
}