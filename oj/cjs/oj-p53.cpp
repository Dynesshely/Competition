#include <iostream>
#include <algorithm>
using namespace std;
int ans=100000,bot[7],_time[21],n,k,i,minn,f[21];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int dep,int tim)
{
	if(tim>=ans)return;
	if(dep==n+1)
	{
		if(ans>tim)ans=tim;
		return;
	}
	for(int j=1;j<=k;j++)
	if(!f[dep]&&bot[j]+_time[dep]<=ans)
	{
		f[dep]=1;
		bot[j]+=_time[dep];
		dfs(dep+1,max(tim,bot[j]));
		f[dep]=0;
		bot[j]-=_time[dep];
	}return;
}
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>_time[i];
	sort(_time+1,_time+n+1,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//int n,k;
//int x[100];
//int x1[100];
//int maxnum=1000000;
//
//void task(int level)
//{
//    if(level>n){
//     int temp=0;
//     for(int i=1;i<=k;i++){
//        if(x[i]>temp){
//            temp=x[i];
//        }
//     }
//     if(temp<maxnum){
//        maxnum=temp;
//     }
//    }
//    else{
//        for(int i=1;i<=k;i++){
//            x[i]+=x1[level];
//            task(level+1);
//            x[i]-=x1[level];
//        }
//    }
//}
//int main()
//{
//    cin >> n;
//    cin >> k;
//    for(int i=1;i<=n;i++){
//        cin >>x1[i];
//    }
//    task(1);
//    cout << maxnum;
//    return 0;
//}