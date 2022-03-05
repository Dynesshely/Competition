#include <bits/stdc++.h>
using namespace std;
long long cal(long long n){
	ostringstream os;
	os << n;
	string ns = os.str();
	long long ans = 0;
	for(int i = 0; i < ns.length(); ++ i)
		ans += ns[i] - '0';
	return ans;
}
int main(){
	long long n, ans = 0;
	scanf("%lld", &n);
	for(long long i = 1; i <= n; ++ i)
		ans += cal(i);
	printf("%lld\n", ans);
	return 0;
}
