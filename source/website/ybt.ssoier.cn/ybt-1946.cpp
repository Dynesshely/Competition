#include <bits/stdc++.h>
using namespace std;
struct stu{
	int	k; // ������ 
	int s; // �ɼ� 
}students[5000];
bool cmp(stu a, stu b){ // ���ɼ��������� �ɼ���ͬ�İ��������������� 
	if(a.s != b.s){
		return a.s > b.s;
	}else{
		return a.k < b.k;
	}
}
int main(){
	int n, m, count = 0; // n - ������  m - �ƻ�¼ȡ���� 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &students[i].k, &students[i].s);
		count ++;
	}
	sort(students, students + count, cmp); // ���� 
	if(m >= n){
		printf("%d %d\n", students[n - 1].s, n);
		for(int i = 0; i < n; ++i){
			printf("%d %d\n", students[i].k, students[i].s);
		}
	}else{
		int lastOne = m * 1.5;
		int line = students[lastOne].s, lastIndex = 0;
		for(int i = 0; i < n; ++i){
			if(students[i].s < line){
				lastIndex = i - 1;
				break;
			}
		}
		printf("%d %d\n", line, lastIndex + 1);
		for(int i = 0; i < lastIndex + 1; ++i){
			printf("%d %d", students[i].k, students[i].s);
			if(i != lastIndex)
				printf("\n");
		}
	}
	return 0;
}
