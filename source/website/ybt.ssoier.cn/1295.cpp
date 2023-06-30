#include <bits/stdc++.h>
using namespace std;
int f[100000],c[100000];
int v,m;
int main(){
	cin >> v >> m;
	for(int i = 1; i <= m; i++)
	cin >> c[i];
	for(int i = 1; i <= m; i++)
	  for(int j = v; j >= c[i];j--)
	    f[j] = max(f[j], f[j-c[i]] + c[i]);
	  printf("%d\n",v - f[v]);
	return 0;
}