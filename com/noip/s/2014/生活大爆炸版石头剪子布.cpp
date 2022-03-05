#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],ans,tot;
int f[10][10]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    cin>>a[i];
    for(int j=0;j<k;j++)
    cin>>b[j];
    for(int i=0;i<n;i++)
    {
        if(f[a[i%m]][b[i%k]]==1)
        ans++;
        if(f[a[i%m]][b[i%k]]==-1)
        tot++;
    }
    cout<<ans<<" "<<tot;
    return 0;
}