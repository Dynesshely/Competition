#include <bits/stdc++.h>
using namespace std;
int *sum, length, delta = 0, x = 0, l1, l2; // x - jinwei
string s1, s2;
int main(){
	getline(cin, s1); getline(cin, s2);
	l1 = s1.length(), l2 = s2.length(), length = max(l1, l2), sum = new int[length + 1];
	for(int i = 0; i <= length; ++ i){ sum[i] = 0; }
	int ss1[length + 1] = {}, ss2[length + 1] = {}, in1 = length, in2 = length;
	for(int i = l1; i > 0; -- i, -- in1){ ss1[in1] = s1[i - 1] - '0'; }
	for(int i = l2; i > 0; -- i, -- in2){ ss2[in2] = s2[i - 1] - '0'; }
	for(int i = length; i >= 0; -- i){
		int tmp = ss1[i] + ss2[i] + x;
		x = tmp >= 10 ? 1 : 0;
		tmp -= tmp >= 10 ? 10 : 0;
		sum[i] = tmp;
	}
	bool start = true;
	for(int i = 0; i <= length; ++ i){
		if(!start){ cout << sum[i]; }
		else if(sum[i] != 0 && start){
			cout << sum[i];
			start = false;
		}
	}
	return 0;
}