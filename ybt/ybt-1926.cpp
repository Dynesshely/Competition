#include <bits/stdc++.h>
using namespace std;

int main(){
	int days[7][2],hours[7],dayindex[7],tmp;
	for(int i=0;i<7;i++){
		dayindex[i]=i+1;
	}
	for(int i=0;i<7;i++){
		cin>>days[i][0]>>days[i][1];
		hours[i]=days[i][0]+days[i][1];
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7-1;j++){
			if(hours[j]>hours[j+1]){
				tmp=hours[j];hours[j]=hours[j+1];hours[j+1]=tmp;
				tmp=dayindex[j];dayindex[j]=dayindex[j+1];dayindex[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<7;i++){
		if(hours[i]>8){
			cout<<dayindex[i];
			return 0; 
		}
	}
	cout<<0;
	return 0;
}
