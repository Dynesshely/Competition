#include <bits/stdc++.h>
using namespace std;

int n, a[10500], index;
ostringstream ans;
int main(){
	freopen("poly.in", "r", stdin);
	freopen("poly.out", "w", stdout);
	
	scanf("%d", &n);
	index = n;
	for(int i = 1; i <= n + 1; ++ i){
		scanf("%d", &a[i]);
		if(a[i] == 0){ --index; continue; }
		if(index == 0){
			ans << (1 * a[i] > 0 ? "+" : "") << 1 * a[i];
			break;
		}
		if(a[i] == 1) ans << "+x";
		else if(a[i] == -1) ans << "-x";
		else ans << (a[i] > 0 ? (index == n ? "" : "+") : "") << a[i] << "x";
		if(index > 0 && index != 1)
			ans << "^" << index;
		--index;
	}
	printf("%s\n", ans.str().c_str());
	return 0;
}
