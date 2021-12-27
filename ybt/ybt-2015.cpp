#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;
typedef long long ll;
const int maxn = 5e5, mod = 1e9 + 7;
int n, k, w[10], c[maxn + 5], d[maxn + 5], dt[10], res, S[11][11], inv[12];
struct foo {
	int z[10], l[10], r[10];
	void reset() {
		memset(z, 0, k << 2);
		memset(l, 0, k << 2);
		memset(r, 0, k << 2);
	}
	foo() {
		reset();
	}
	int walk(int c, int d) {
		z[c] += d;
		if (z[c] < l[c] || z[c] > r[c]) {
			l[c] = min(l[c], z[c]);
			r[c] = max(r[c], z[c]);
			return d;
		}
		return 0;
	}
} F, B;
inline void red(int &x) {
	x += x >> 31 & mod;
}
void prework(int n) {
	S[0][0] = 1;
	rep(i, 1, n) rep(j, 1, i) {
		S[i][j] = (S[i - 1][j - 1] + ll(S[i - 1][j]) * j) % mod;
	}
	inv[1] = 1;
	rep(i, 2, n + 1) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
	}
}
int calc(int k, int n) {
	int s = 0, c = 1;
	rep(i, 0, k) {
		c = ll(c) * max(0, n - i) % mod;
		s = (s + ll(c) * inv[i + 1] % mod * S[k][i]) % mod;
	}
	return s;
}
int work(int a[]) {
	int lim = mod;
	rep(i, 0, k - 1) if (dt[i]) {
		lim = min(lim, (a[i] + dt[i] - 1) / dt[i]);
	}
	int dp[11] = { 1 };
	rep(i, 0, k - 1) {
		per(j, i, 0) {
			dp[j + 1] = (dp[j + 1] + ll(mod - dt[i]) * dp[j]) % mod;
			dp[j] = ll(a[i]) * dp[j] % mod;
		}
	}
	int res = 0;
	rep(i, 0, k) {
		res = (res + ll(dp[i]) * calc(i, lim)) % mod;
	}
	return res;
}
int main() {
	// freopen("walk.in", "r", stdin);
	// freopen("walk.out", "w", stdout);
	scanf("%d %d", &n, &k);
	prework(k);
	rep(i, 0, k - 1) {
		scanf("%d", &w[i]);
	}
	rep(i, 1, n) {
		scanf("%d %d", &c[i], &d[i]), c[i]--;
		if (F.walk(c[i], d[i]) && F.r[c[i]] - F.l[c[i]] <= w[c[i]]) {
			int x = 1;
			rep(j, 0, k - 1) if (j != c[i]) {
				x = ll(x) * max(0, w[j] - F.r[j] + F.l[j]) % mod;
			}
			res = (res + ll(i) * x) % mod;
		}
	}
	rep(i, 1, n) if (F.z[c[i]] < 0) {
		d[i] = -d[i];
	}
	rep(i, 0, k - 1) if (F.z[i] < 0) {
		F.z[i] = -F.z[i];
		swap(F.l[i], F.r[i]);
		F.l[i] = -F.l[i];
		F.r[i] = -F.r[i];
	}
	B = F;
	bool chk = true;
	rep(i, 0, k - 1) {
		dt[i] = B.z[i];
		chk &= dt[i] == 0;
	}
	if (chk) {
		bool ok = false;
		rep(i, 0, k - 1) {
			ok |= B.r[i] - B.l[i] >= w[i];
		}
		printf("%d\n", ok ? res : -1);
		exit(0);
	}
	int a[10] = {};
	rep(i, 1, n) {
		if (F.walk(c[i], d[i]) && F.r[c[i]] - F.l[c[i]] <= w[c[i]]) {
			bool ok = true;
			rep(j, 0, k - 1) if (j != c[i]) {
				ok &= w[j] - F.r[j] + F.l[j] > 0;
			}
			if (!ok) {
				continue;
			}
			rep(j, 0, k - 1) if (j != c[i]) {
				a[j] = w[j] - F.r[j] + F.l[j];
			}
			a[c[i]] = w[c[i]] - F.r[c[i]] + F.l[c[i]] + 1, res = (res + ll(i) * work(a)) % mod;
			a[c[i]] = w[c[i]] - F.r[c[i]] + F.l[c[i]], res = (res + ll(mod - i) * work(a)) % mod;
		}
	}
	rep(i, 0, k - 1) {
		a[i] = max(0, w[i] - B.r[i] + B.l[i]);
	}
	res = (res + ll(n) * work(a)) % mod;
	printf("%d\n", res);
	return 0;
}

