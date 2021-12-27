#include <bits/stdc++.h>
using namespace std;
struct stu{
	string name;
	int grades;
}students[110];
bool cmp(stu a, stu b){
	return a.grades > b.grades;
}
int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> students[i].grades >> students[i].name;
	}
	sort(students, students+N, cmp);
	cout << students[0].name;
	return 0;
}
