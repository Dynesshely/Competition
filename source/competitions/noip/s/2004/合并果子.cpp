#include <bits/stdc++.h>
using namespace std;
int sum = 0, n;
priority_queue<int, vector<int>, greater<int> > fruits;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		int tmp;
		scanf("%d", &tmp);
		fruits.push(tmp);
	}
	int a = 0, b = 0;
	int size = fruits.size();
	while(size > 1){
		a = fruits.top();
		fruits.pop();
		b = fruits.top();
		fruits.pop();
		fruits.push(a + b);
		sum += a + b;
		--size;
	}
	printf("%d\n", sum);
	return 0;
}
