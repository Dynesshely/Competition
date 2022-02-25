#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    long double xa = 1.0 / sqrt(5), xb = (1.0 + sqrt(5)) / 2, xc = (1.0 - sqrt(5)) / 2;
    ostringstream os;
    os << xa * (pow(xb, n) - pow(xc, n));
    printf("%s\n", os.str().c_str());
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// long long via[100001];
// long long f(int n){
// 	if(n == 1 || n == 2) return 1;
// 	else{
// 		long long tmp = (via[n - 1] == 0 ? f(n - 1) : via[n - 1]) + (via[n - 2] == 0 ? f(n - 2) : via[n - 2]);
// 		via[n] = tmp;
// 		return tmp;
// 	}
// }
// int main(){
// 	via[1] = via[2] = 1;
// 	int n;
// 	scanf("%d", &n);
// 	printf("%lld\n", f(n));
// 	return 0;
// }