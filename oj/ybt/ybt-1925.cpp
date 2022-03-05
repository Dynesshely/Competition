#include <bits/stdc++.h>
using namespace std;

int len(int u[])
{
	return sizeof(u)/sizeof(u[0]);
}

string add_hpc(int a[],int b[])
{
	int c[1000], i=1, x=0;
	while((i<=len(a))||(i<=len(b)))
	{
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
		i++;
	}
	string output;
	for(int i=0;i<len(c);i++)
	{
		output+=c[i];
	}
}

int* convert(int come)
{
	string oo=come;
	int p[oo.length()];
	for(int i=0;i<oo.length();i++)
	{
		p[i]=oo[i];
	}
	return p;
}

int main()
{
	int p=0,o=0;
	cin>>p>>o;
	cout<<add_hpc(convert(p),convert(o));
	return 0;
}
