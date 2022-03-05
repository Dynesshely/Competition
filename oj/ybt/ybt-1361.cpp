#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans=1,t=0;
string ch[100001];
char a[21][3];
inline int right(string s){
	for(int i=1;i<ans;i++)
		if(ch[i]==s) return 1;
	return 0;
}
inline void jqsh(){
	do{
		t++;
		for(int i=0;i<ch[t].size();i++){
			for(int j=1;j<=n;j++){
				if(ch[t][i]==a[j][1]){
					ch[++ans]=ch[t];
					ch[ans][i]=a[j][2];
					if(right(ch[ans])) ans--;
				}
			}
		}
	}while(t<ans);
	return;
}
int main(){
	cin>>ch[1];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	jqsh();
	printf("%d\n",ans);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int n, k, ton[20000];
//int main(){
//	scanf("%d %d", &n, &k);
//	ostringstream os; os << n;
//	string n_str = os.str();
//	for(int i = 0; i < k; ++ i){
//		char from, to;
//		scanf("%c %c", &from, &to);
//		string tmp;
//		strcpy(tmp, n_str);
//		for(int j = 0; j < tmp.length(); ++ j){
//			if(tmp[j])
//		}
//	}
//	return 0;
//}
