#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string input;
	int count = 0;
	cin>>input;
	char *arr = new char[input.length()+1];
	memmove(arr,input.c_str(),input.length());
	for(int i=0;i<input.length()+1;i++)
	{
		if((arr[i]-'0')==1)
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}
