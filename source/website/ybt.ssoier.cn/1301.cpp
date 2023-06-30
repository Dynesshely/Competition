#include <bits/stdc++.h>
using namespace std;
int T = 0, n = 0, arr[100010], dp[100010], ans = 0;
inline void term(){
	scanf("%d", &arr[1]);
	ans = dp[1] = arr[1];
	for(int i = 2; i <= n; ++ i){
		scanf("%d", &arr[i]);
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
		ans = max(dp[i], ans);
	}
	printf("%d\n", ans);
}
int main(){
	scanf("%d", &T);
	for(int r = 0; r < T; ++r){
		scanf("%d", &n);
		term();
	}
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int T = 0, n = 0;
//void term(){
//	int arr[100100],dp[100100],ans=0;
//	for(int i = 1; i <= n; ++ i){
//		scanf("%d", &arr[i]);
//	}
//	
//	ans = dp[1] = arr[1];
//	
//	for(int i = 2; i <= n; i ++){
//		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
//		ans = max(dp[i], ans);
//	}
//	printf("%d\n", ans);
//}
//int main(){
//	scanf("%d", &T);
//	for(int r = 0; r < T; ++r){
//		scanf("%d", &n);
//		term();
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int T = 0, n = 0;
//void term(){
//	int arr[n];
//	for(int i = 0; i < n; ++ i){
//		scanf("%d", &arr[i]);
//	}
//	if(n > 3){
//		for(int i = 0; i < n; ++ i){
//			if(i >= 3){
//				arr[i] = max(arr[i] + arr[i - 2], arr[i - 1]);
//			}
//		}
//	}else if(n == 3){
//		arr[n - 1] = max(arr[n - 1] + arr[n - 3], arr[n - 2]);
//	}else if(n == 2){
//		arr[n - 1] = max(arr[n - 1], arr[n - 2]);
//	}
//	printf("%d", arr[n - 1]);
//}
//int main(){
//	scanf("%d", &T);
//	for(int r = 0; r < T; ++r){
//		scanf("%d", &n);
//		term();
//	}
//	return 0;
//}
