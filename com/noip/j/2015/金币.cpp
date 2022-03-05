#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k,count=0,sn,n=1;
	cin>>k;
	while(true)
	{
		sn=(1+n)*n/2;
		if(sn>k)
		{
			n--;
			sn=(1+n)*n/2;
			break;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				count+=n; 
			}
			n++;
		}
	}
	for(int i=0;i<k-sn;i++)
	{
		count+=n+1;
	}
	cout<<count;
	return 0;
}
