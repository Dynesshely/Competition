#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int n,x,count=0;
	cin>>n>>x;
	for(int i=n;i<x+1;i++)
	{
		ostringstream os;
		os<<i;
		string ss = os.str();
		char *arr = new char[ss.length()+1];
		memmove(arr,ss.c_str(),ss.length());
		for(int j=0;j<ss.length()+1;j++)
		{
			if((arr[j]-'0')==2)
			{
				count=count+1;
			}
		}
	}
	cout<<count<<endl;
	return 0;
} 
