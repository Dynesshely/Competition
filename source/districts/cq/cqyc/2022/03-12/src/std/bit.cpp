#include <cstdio>
int n, k;
int count(int x) {
	int r = 0;
	while (x) {
		r += x & 1;
		x >>= 1;
	}
	return r;
}
int main() {
	freopen("bit.in","r",stdin);
	freopen("bit.out","w",stdout); 
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - i * k; i++) {
		if (count(n - i * k) <= i) {
			printf("%d", i);
			return 0;
		}
	}
	puts("-1");
}
