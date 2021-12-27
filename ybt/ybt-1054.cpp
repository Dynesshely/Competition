#include <bits/stdc++.h>
using namespace std;
int main()
{
	int bian[3];
	cin>>bian[0]>>bian[1]>>bian[2];
	if(bian[0]+bian[1]>bian[2] && bian[1]+bian[2]>bian[0] && bian[0]+bian[2]>bian[1]){
		if(bian[0]-bian[1]<bian[2] && bian[1]-bian[2]<bian[0] && bian[0]-bian[2]<bian[1]){
			cout<<"yes";
			return 0;
		}
	}
	cout<<"no";
    return 0;
}
