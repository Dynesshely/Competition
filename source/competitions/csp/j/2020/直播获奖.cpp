#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int main() {
	int n, tmp, res, pro;
	scanf("%d %d", &n, &pro);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
		res = i * pro / 100;
		res = max(res, 1);
		for (int i = 600; i >= 0; i--) {
			if (res - arr[i] <= 0) {
				printf("%d ", i);
				break;
			}
			res -= arr[i];
		}
	}
	return 0;
}

// 该实现超时了 
//#include <bits/stdc++.h>
//using namespace std;
//int n, w, added=0, last=0;
//int main(){
//	scanf("%d %d", &n, &w);
//	int grades[n];
//	for(int i=0;i<n;++i){
//		scanf("%d", &grades[i]);
//		++added;
//		if(added && grades[i] != last){
//			if(grades[i] < grades[i-1]){
//				sort(grades, grades + added);
//			}
//			int crowd = added * w / 100.0;
//			last = grades[added - (crowd ? crowd : 1)];
//		}else{
//			last = grades[i];
//		}
//		printf("%d%s", last, (i == n-1 ? "" : " "));
//	}
//	return 0;
//}

// Hello VIM
