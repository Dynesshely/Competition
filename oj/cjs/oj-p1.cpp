/*
	Description
	某大型游乐园发起园内各个游玩项目受欢迎度调查，园内共有 n (1≤n≤999)个项目，每个项目的编号分别从 1 到 n ，现在收集到了m(1≤m≤100000)张投票，每张票都写了一个最喜欢的游乐项目的编号。现在想把收集到的这些票按照票上的编号从小到大排序。输入 n 和 m 以及 m 张票上的编号，求出排序后的投票编号。

	Format
	Input
	第一行输入两个整数𝑛𝑛 (1≤n≤999)和m(1≤m≤100000),分别表示游乐项目总数和收到的投票总数。 第二行输入 m 个整数，依次表示每张投票上的游乐项目的编号。

	Output
	输出一行，包含 m 个整数，相邻整数间用一个空格分隔，依次表示排序后的投票编号。
*/

#include <bits/stdc++.h>
using namespace std;
int n, m, s[100010];
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++ i) { int tmp; scanf("%d", &tmp); s[tmp] ++; }
	for(int i = 1; i <= n; ++ i)
		if(s[i] != 0)
			for(int j = 1; j <= s[i]; ++ j)
				printf("%d ", i);
	printf("\n");
	return 0;
}
