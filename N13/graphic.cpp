#include <bits/stdc++.h>
using namespace std;
int MIN = 0x7fffffff;
void dj(int w[][], int tar, int n, int sons[][], int s, int bp[], int bpv[]){
	for(int i = 1; i <= sons[s][0]; ++ i){
		int index = sons[s][i];
		bpv[index] = bpv[s] + w[s][index];
		MIN = min(bpv[index], MIN);
		dj(w, tar, n, sons, index, bp, bpv);
	}
}
int main(){
	int n, ws;
	cin >> n;
	int w[n+1][n+1];
	int sons[n+1][n+1];
	memset(w, -1, sizeof(w));
	memset(sons, 0, sizeof(sons));
	cin >> ws;
	for(int i = 0; i < ws; ++ i){
		int x, y, l;
		cin >> x >> y >> l;
		w[x][y] = l;
		sons[x][++sons[x][0]] = y;
	}
	int target;
	cin >> target;
	dj(w, target, n, sons, 1);
	cout << MIN << endl;
	return 0;
}
