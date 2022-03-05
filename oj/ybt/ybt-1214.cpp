#include<bits/stdc++.h>
using namespace std;
bool d[10010]={0},b[10010]={0},c[10010]={0};
int n=8,nn,N,sum=0,a[10010],x=0;
void dfs(int);
void print();
int main()
{
	cin>>N;
	int i=0;
	while(i<N)
	{
		x=0;
		cin>>nn;
		dfs(1);
		i++;
	}
	return 0;
}
void print()
{ 
	x++;
	if(x==nn)
	{
		int i;
		for(i=1;i<=n;i++)
			cout<<a[i];
		cout<<endl;
	}
}
void dfs(int i)
{
	int j;
	for(j=1;j<=n;j++)
		if((!b[j])&&(!c[i+j])&&(!d[i-j+n-1]))
		{
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+n-1]=1;
			if(i==n)
				print();
			else
				dfs(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+n-1]=0;
		}
}