#include <bits/stdc++.h>
#define MAXN 101
#define SIZE families.size()
using namespace std;
int n, k, maniest = 0, flag[MAXN];
struct rlt{ // relative
	int left;
	int right;
}rls[MAXN];
struct family{
	int num;
	int members[MAXN];
};
queue<family> families;
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; ++ i){
		scanf("%d %d", &rls[i].left, &rls[i].right);
		flag[rls[i].left] = 1;
		flag[rls[i].right] = 1;
		bool existFam = false;
		for(int j = 0; j < SIZE; ++ j){
			family *f = &families.front();
			maniest = (f->num > maniest ? f->num : maniest);
			for(int p = 0; p < f->num; ++ p){
				if(rls[i].left == f->members[p]){
					f->members[f->num] = rls[i].right;
					f->num++;
					existFam = true;
					break;
				}
				if(rls[i].right == f->members[p]){
					f->members[f->num] = rls[i].left;
					f->num++;
					existFam = true;
					break;
				}
			}
			families.push(*f);
			families.pop();
		}
		if(existFam == false){
			family f;
			f.num = 2;
			f.members[0] = rls[i].left;
			f.members[1] = rls[i].right;
			families.push(f);
		}
	}
	for(int i = 1; i <= n; ++ i){
		if(flag[i] != 1){
			family f;
			f.num = 1;
			f.members[0] = i;
			families.push(f);
			maniest = 1 > maniest ? 1 : maniest;
		}
	}
	printf("%d %d\n", families.size(), maniest);
	return 0;
}
