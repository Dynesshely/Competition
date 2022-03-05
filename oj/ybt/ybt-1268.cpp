#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int qread(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int i, j, m, n, wi, ci, f[N] = {0};
int main(){
	m = qread();
    n = qread();
	for(i = 1;i <= n; i ++) {
		wi = qread();
        ci = qread();
		for(j = wi; j <= m; j ++)
			if(f[j] < f[j-wi] + ci){
                f[j]=f[j-wi]+ci;
            }
	}
	printf("max=%d\n", f[m]);
	return 0;
}