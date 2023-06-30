#include <bits/stdc++.h>
using namespace std;
int N, sonnum[110], tmp;
vector<int> sons;
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++ i){
		while(true){
			scanf("%d", &tmp);
			if(tmp == 0) break;
			else{
				sons[i][sonnum[i]] = tmp;
				++ sonnum[i];
			}
		}
	}
	return 0;
}