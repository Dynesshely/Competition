#include <bits/stdc++.h>
using namespace std;
struct stu{
	int k; int s;
}students[5000];
bool cmp(stu a, stu b){
	if(a.s != b.s){
		return a.s > b.s;
	}else{
		return a.k < b.k;
	}
}
int main(){
	int n, m, count = 0;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;++i){
		scanf("%d %d", &students[i].k, &students[i].s);
		count++;
	}
	sort(students, sthdents + count, cmp);
	return  0;
}
