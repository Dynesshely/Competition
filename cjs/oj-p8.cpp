#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	int n, tmp, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		scanf("%d", &tmp);
		q.push(tmp);
	}
	while(q.size() != 1){
		int a = q.top(), b;
		q.pop();
		b = q.top();
		q.pop();
		sum += a + b;
		q.push(a + b);
	}
	printf("%d\n", sum);
	return 0;
}