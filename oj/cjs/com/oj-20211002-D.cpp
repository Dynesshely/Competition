#include <bits/stdc++.h>
using namespace std;
long long n, m, a[8] = {912, 7136, 56768, 453504, 3626752}, mypow(long long a, long long b), mod = 1e9 + 7;
int main(){
	scanf("%lld %lld", &n, &m);
	if(n > m) swap(n, m);
	if(n <= 3){
		switch(n){
			case 1: printf("%lld\n", mypow(2, m)); break;
			case 2: printf("%lld\n", (12 * mypow(3, m - 2)) % mod); break;
			case 3: printf("%lld\n", (112 * mypow(3, m - 3)) % mod); break;
		}
	}
    else if(n == m) printf("%lld\n", a[n - 4]);
    else printf("%lld\n", 3 * (a[n - 4] - mypow(2, n)) * mypow(3, m - n - 1) % mod);
	return 0;
}
long long mypow(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}