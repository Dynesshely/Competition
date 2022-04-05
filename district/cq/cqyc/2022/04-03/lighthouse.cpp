#include<cstdio>
 
char B[1<<22],*S=B,*T=B;
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<22,stdin),S==T)?EOF:*S++)
const int maxn = 7500100;
int n, t, r, last, pre, j;
int X[maxn];
 
int read() {
	int a = 0;
	char ch;
	while((ch = getchar()) < 48);
	while(ch >= 48 && ch <= 57) a = (a << 3) + (a << 1) + (ch ^ 48), ch = getchar();
	return a;
}
int main() {
	freopen("lighthouse.in","r",stdin);
	freopen("lighthouse.out","w",stdout);
	n = read(), t = read(), r = read();
	for(int i = 1; i <= n; ++i)
		X[i] = read();
	pre = 1, j = 1;
	while(j <= n && t) {
		while(j <= n && X[j] - X[pre] <= r)
			j++;
		last = --j, --t;
		while(j <= n && X[j] - X[last] <= r)
			j++;
		pre = j;
	}
	return !printf("%d\n", --j);
}
