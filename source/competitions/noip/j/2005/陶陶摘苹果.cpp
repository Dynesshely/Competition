#include <bits/stdc++.h>
using namespace std;

int main()
{
	int apples[10],height,chair=30,tmp;
	for(int i=0;i<10;i++)
	{
		cin>>apples[i];
	}
	cin>>height;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10-1;j++)
		{
			if(apples[j]>apples[j+1])
			{
				tmp=apples[j];apples[j]=apples[j+1];apples[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		if(apples[i]>height+chair)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
