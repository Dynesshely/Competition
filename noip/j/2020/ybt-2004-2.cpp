#include<bits/stdc++.h>
using namespace std;
stack<long long>ss;
int main() {
	long long n;
	scanf("%lld",&n);
	//n=4294967294;
	if (n % 2)
		cout << -1 << endl;
	else {
		long long index = -1;
		while (n) {
			index++;
			if (n & 1) 
				ss.push(pow(2, index));
			n >>= 1;
		}
		while (!ss.empty()) {
			cout << ss.top() << " ";
			ss.pop();
		}
	}
	return 0;
}
