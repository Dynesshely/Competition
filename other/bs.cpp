#include <bits/stdc++.h>
using namespace std;

struct n{
	int v;
};

bool operator > (const n &a, const n &b){
	return (a).v > (b).v;
}

int main(){
	n n1, n2;
	n1.v = 10, n2.v = 20;
	cout << (n1 > n2);
	return 0;
}