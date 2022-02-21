/*
	贵青杯赛事题或者训练题
*/

#include<bits/stdc++.h>
using namespace std;
int n;
int l[25];
int len;
bool dfs(int a,int b,int c,int id)
{
    if(a==b&&b==c&&id==n) return true;
    if(a>len||b>len||c>len) return false;
    if(id>=n) return false;
    if(dfs(a+l[id],b,c,id+1)||dfs(a,b+l[id],c,id+1)||dfs(a,b,c+l[id],id+1)) return true;
    return false;
}
int main()
{
    cin>>n;
    int sum=0;
    int maxn=-1;
    for(int i=0; i<n; i++)
    {
        cin>>l[i];
        sum+=l[i];
        maxn=max(maxn,l[i]);
    }
    if((sum/3*3)!=sum||maxn>(sum/3))
    {
        cout<<"no"<<endl;
        return 0;
    }
    int a,b,c;
    a=b=c=0;
    len=sum/3;
    if(dfs(a,b,c,0)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}