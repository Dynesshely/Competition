#include <bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
	string input;
	int n; scanf("%d", &n);
	cin >> input;
	if(input.length() % 2 == 0){
		int index = 0;
		while(s.size() > 0 && index < input.length()){
			if(input[index] == '(')
				s.push('(');
			else{
				char tmp = s.top();
				if(tmp != '('){
					printf("NO\n");
					return 0;	
				}else s.pop();
			}
			index ++;
		}
		if(s.size() == 0)
			printf("YES\n");
		else printf("NO\n");
	}else printf("NO\n");
	return 0;
}