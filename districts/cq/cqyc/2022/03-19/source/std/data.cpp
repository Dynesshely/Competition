#include <bits/stdc++.h>
using namespace std;
string s[10010];
bool cmp(const string& a, const string& b) 
{
	if(a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i != n; ++i) cin >> s[i], assert(s[i].size() <= 100u);
	sort(s, s + n, cmp);
	for(int i = 0; i != n; ++i) cout << s[i] << '\n';
}
