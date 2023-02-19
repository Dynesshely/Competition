#include <bits/stdc++.h>
using namespace std;
int main(){
	string s, s1, s2;
	long long times = 0;
	cin >> s1 >> s2;
	freopen("tokens.txt", "r", stdin);
	getline(cin, s);
	s1 = " " + s1 + " ";
	s2 = " " + s2 + " ";
	clock_t start_replace = clock();
	for(int k=0;(k=s.find(s1, k)) >= 0;k+=s2.size()-1){
		s.replace(k, s1.size(), s2);
		times++;
	}
	clock_t end_replace = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double readingTimes = ((double) end_replace - start_replace) / CLOCKS_PER_SEC;
	cout << times << "\tused " << readingTimes << " sec" << endl;
	return 0;
}
