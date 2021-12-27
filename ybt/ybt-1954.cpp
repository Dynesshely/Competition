#include <bits/stdc++.h>
using namespace std;
int main()
{
	string input,tline;
	int count=0,location=0;
	getline(cin,input);
	getline(cin,tline);
	for(int i=0;i<tline.length();i++){
		if('A'<=tline[i] && tline[i]<='Z'){
			tline[i]+32;
		}
	}
	bool found=false;
	for(int i=0;i<tline.length();i++){
		if(tline[i]==input[0] && (i==0 ? true : tline[i-1]==32)){
			bool allPass=true;
			for(int j=0;j<input.length();j++){
				if(!(input[j]==tline[i+j] || input[j]==tline[i+j]+32 || input[j]==tline[i+j]-32) || (j==input.length()-1 && tline[i+j+1] != 32)){
					allPass=false;
				}
			}
			if(allPass){
				count++;
				if(!found){
					location=i;
					found=true;
				}
			}
		}
	}
	cout<<count<<" "<<location;
//	int index=0,last=0;
//	list<string> tokens;
//	while(index < tline.length()){
//		if(tline[index]==32){
//			string token;
//			for(int i=last;i<index;i++){
//				token+=tline[i];
//			}
//			last=index+1;
//			tokens.push_back(token);
//		}else if(index==tline.length()-1){
//			string token;
//			for(int i=last;i<tline.length();i++){
//				token+=tline[i];
//			}
//			tokens.push_back(token);
//		}
//		index ++;
//	}
//	for(list<string>::iterator it = tokens.begin(); it!=tokens.end();++it){
//		string now=*it;
//		if(now.length()==input.length()){
//			
//		}
//	}
    return 0;
} 
