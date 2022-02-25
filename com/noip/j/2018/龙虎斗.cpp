#include <bits/stdc++.h>
using namespace std;
long long arr[100010];
int main() {
	long long m, p, s1, s2, n, left = 0, right = 0, pos = 0, cmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m >> p >> s1 >> s2;
	arr[p] += s1;
	for (int i = 1; i < m; i++)    //计算龙的气势
		left += arr[i] * (m - i);
	for (int j = m + 1; j <= n; j++)   //计算虎的气势
		right += arr[j] * (j - m);
	cmp = abs(left - right);   //标记气势差
	pos = m;   //将初始位置置为m
	for (int i = 1; i <= n; i++)   //不断尝试
		if (i < m) {
			if (abs(s2 * (m - i) + left - right) < cmp) {
				pos = i;
				cmp = abs(s2 * (m - i) + left - right);
			}
		}
		else if (i > m) {
			if (abs(s2 * (i - m) + right - left) < cmp) {
				pos = i;
				cmp = abs(s2 * (i - m) + right - left);
			}
		}
	cout << pos << endl;
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int n,m,p1,s1,s2,smallest=0,index=0;
//	scanf("%d",&n);
//	int ss[n];
//	for(int i=0;i<n;++i){
//		scanf("%d",&ss[i]);
//	}
//	scanf("%d %d %d %d",&m,&p1,&s1,&s2);
//	ss[p1-1]+=s1;
//	int loc=m-1;
//	
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int n,m,p1,s1,s2,smallest=0,index=0;
//	scanf("%d",&n);
//	int ss[n];
//	for(int i=0;i<n;++i){
//		scanf("%d",&ss[i]);
//	}
//	scanf("%d %d %d %d",&m,&p1,&s1,&s2);
//	ss[p1-1]+=s1;
//	int loc=m-1;
//	for(int i=0;i<n;++i){
//		ss[i]+=s2;
//		int left=0,right=0,tmp,tmp1;
//		for(int j=0;j<n;++j){
//			if(j<loc){
//				left+=ss[j]*(loc-j);
//			}else if(j>m-1){
//				right+=ss[j]*(j-loc);
//			}
//		}
//		tmp1=left-right;
//		tmp=(tmp1>=0?tmp1:tmp1*-1);
//		if(i>0){
//			if(tmp<smallest){
//				smallest=tmp;
//				index=i;
//			}
//		}else{
//			smallest=tmp;
//		}
//		ss[i]-=s2;
//	}
//	printf("%d",index+1);
//	return 0;
//}
