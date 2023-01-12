#include <cstdio>
typedef unsigned long long ull;
ull n, m, a, b, r;
bool c[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%llu%llu%llu", &n, &a, &b);
	m = n * a + b;
	for (ull i = a + b; i <= m; i += a)
		if (!c[(i - b) / a] && ++r)
			for (ull j = i * 2; j <= m; j += i)
				if (!((j - b) % a)) c[(j - b) / a] = true;
	printf("%llu", r);
}
