#include <bits/stdc++.h>
using namespace std;
struct per{
	int id; int yuwen; int shuxue; int yinyu; int sum;
}score[310];
bool cmp(per a,per b){
	if(a.sum!=b.sum){ return a.sum > b.sum;
	}else if(a.yuwen != b.yuwen){ return a.yuwen > b.yuwen;
	}else{ return a.id < b.id; }
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		per one;
		cin >> one.yuwen >> one.shuxue >> one.yinyu;
		one.sum = one.yuwen + one.shuxue + one.yinyu;
		one.id = i + 1;
		score[i] = one;
	}
	sort(score,score+n,cmp);
	for(int i=0;i<5;++i){
		cout<<score[i].id<<" "<<score[i].sum<<endl;
	}
	return 0;
}
