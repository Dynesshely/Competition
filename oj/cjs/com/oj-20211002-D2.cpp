#include<bits/stdc++.h>
#define MAX 350
using namespace std;
long long N, each_gold[MAX], answer = -9999999;
bool lu[MAX][MAX];
string tujin = "";
bool exist(queue<int> via, int tar)
{
	int len = via.size();
	for(int i = 0; i < len; ++ i)
	{
		if(via.front() == tar) return true;
		via.push(via.front());
		via.pop();
	}
	return false;
}
long long dfs(int i, long long golds, queue<int> via)
{
	if(exist(via, i)) return golds - each_gold[i];
	else via.push(i);
	long long temp = golds;
	for(int j = 1; j <= N; ++ j)
		if(lu[i][j] && i != j) temp = max(temp, dfs(j, golds + each_gold[j], via));
	if(temp > answer)
	{
		answer = temp; tujin = "";
		int len = via.size();
		for(int i = 0; i < len; ++ i)
		{
			ostringstream os; os << via.front();
			tujin += os.str();
			tujin += i == len - 1 ? "" : "-";
			via.push(via.front()); via.pop();
		}
	}
	return temp;
}
int main()
{
	cin>>N;
	for(int i = 1; i <= N; ++ i) cin>>each_gold[i];
	while(true)
	{
		int a, b;
		cin>>a>>b;
		if(a == 0 && b == 0) break;
		else lu[a][b] = true;
	}
	for(int i = 1; i <= N; ++ i)
	{
		queue<int> via;
		dfs(i, each_gold[i], via);
	}
	cout<< tujin.c_str() << endl << answer;
	return 0;
}