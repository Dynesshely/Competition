#include<cstdio>
#include<algorithm>
 
const int maxn = 2e5 + 10;
typedef long long ll;
int n, trie[2][maxn * 60], tot, maxb;
ll ar[maxn], res;
 
ll read() {
	ll a = 0;
	char ch;
	while((ch = getchar()) < 48);
	while(ch >= 48 && ch <= 57) a = (a << 3) + (a << 1) + (ch ^ 48), ch = getchar();
	return a;
}
void cmin(ll &a, ll b) {b < a ? a = b : 0; }
void build(ll x) {
	int now = 0;
	ll cnt = res;
	for(; ~cnt; cnt--)
		now = trie[(x >> cnt) & 1][now] ? trie[(x >> cnt) & 1][now] : (trie[(x >> cnt) & 1][now] = ++tot);
}
ll query(ll x) {
	int now = 0, cnt = res;
	ll cur = 0;
	for(; ~cnt; cnt--) {
		int tmp = trie[(x >> cnt) & 1][now];
		if(!tmp)
			tmp = trie[((x >> cnt) & 1) ^ 1][now], cur |= (1ll << cnt);
		now = tmp;
	}
	return cur;			
}
int main() {
	freopen("msc.in","r",stdin);
	freopen("msc.out","w",stdout);
	n = read();
	for(int i = 1; i <= n; ++i)
		ar[i] = read();
	std::sort(ar + 1, ar + n + 1);
	if(ar[1] == ar[n])
		return puts("0"), 0;
	for(int i = 59; i; --i)
		if(((ar[1] ^ ar[n]) >> i) & 1) {
			res = i;
			break;
		}
	ll val = 2e18;
	for(int i = n; i; --i)
		(ar[i] >> res) & 1 ? build(ar[i]) : cmin(val, query(ar[i]));
	printf("%lld\n", val);
	return 0;
}
