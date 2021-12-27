#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,tmp,lastAdd,count=0;
	cin>>N;
	int rands[N],effective[N];
	for(int i=0;i<N;i++){
		cin>>rands[i];
	}
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(rands[j]>rands[j+1]){
				tmp=rands[j];
				rands[j]=rands[j+1];
				rands[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(i==0){
			effective[count]=rands[i];
			lastAdd=rands[i];
			count++;
		}else{
			if(rands[i]!=lastAdd){
				effective[count]=rands[i];
				lastAdd=rands[i];
				count++;
			}
		}
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		if(effective[i]!=-1){
			cout<<effective[i]<<(i == count-1 ? "" : " ");
		} 
	}
	return 0;
}
