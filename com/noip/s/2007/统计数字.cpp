#include <bits/stdc++.h>
using namespace std;
map<int, int> nums;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		nums[in]++;
	}
	map<int, int>::iterator iter;
  iter = nums.begin();
  while(iter != nums.end()) {
		printf("%d %d\n", (*iter).first, (*iter).second);
    iter++;
  }
	return 0;
}
