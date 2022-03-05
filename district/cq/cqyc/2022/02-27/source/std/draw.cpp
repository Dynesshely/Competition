#include <bits/stdc++.h>
using namespace std;
 
int N, dp[305][305];
 
int main() {
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	cin >> N;
	vector<int> a(N); 
	for (int i = 0 ; i < N ; ++i) cin >> a[i];
	for (int i = N-1; i >= 0; --i) 
		for (int j = i+1; j < N; ++j) {
			if (a[i] == a[j]) 
				dp[i][j] = max(dp[i][j],1+dp[i+1][j-1]);
			for (int k = i+1; k < j; ++k) 
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
		}
	cout << N-dp[0][N-1] << "\n";
}
