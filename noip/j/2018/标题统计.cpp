#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;
	int count = 0;
	getline(cin,input);
	for(int i=0;i<input.length();i++)
	{
		if(('A'<=input[i] && input[i]<='Z') || ('a'<=input[i] && input[i]<='z') || ('0'<=input[i] && input[i]<='9'))
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}
