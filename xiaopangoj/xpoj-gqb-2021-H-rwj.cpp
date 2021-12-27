#include<bits/stdc++.h>
using namespace std;
string a;
int d;
void suan(int x)
{
	for(int i=0;i<x/2;i++)
	{
		if(a[i]!=a[x-1-i])
		{
			cout<<x;
		}
	}
	d=d/2;
	suan(d);
}
int main(){
	getline(cin,a);
	if(a.size()%2!=0)
	{
		cout<<a.size();
		return 0;
	}
	d=a.size();
	suan(d);
	return 0;
}